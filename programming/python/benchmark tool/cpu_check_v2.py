import time
import multiprocessing


def func(i:int):
    for j in range(50):
        pass


if __name__ == '__main__':
    start = time.time()
    processes = []
    count = 0
    
    for i in range(100):
        p = multiprocessing.Process(target=func, args=(i, ))
        processes.append(p)
        p.start()
    for process in processes:
        count += 1
        process.join()
    
    print("Score ", round(100000*(1/(time.time() - start)/count)))



