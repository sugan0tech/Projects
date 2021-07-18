import time
from datetime import datetime
import multiprocessing


def timer(func):
    def warper():
        before = time.time()
        func(lst)
        return time.time() - before
    return warper

lst = []

@timer
def mem(lst:list):
    for i in range(100000000):
        lst.append(i)

def func(i:int):
    for j in range(50):
        pass

def cpu():
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
    
    return (time.time() - start)/count


if __name__ == '__main__':
    cpu_score = round(10*(1/(cpu())))
    mem_score = round(1000*(4/(mem())))
    file = open("score.txt", "a")
    file.write(f"\ntime : {datetime.now()} | CPU Score : {cpu_score} | MEM Score : {mem_score}")
    file.close()

    print("CPU ---> Score :", cpu_score)
    print("MEM ---> Score :", mem_score)