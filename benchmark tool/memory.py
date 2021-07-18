import time
import multiprocessing

def timer(func):
    def warper():
        before = time.time()
        func(lst)
        print(time.time() - before) 
    return warper

lst = []
@timer
def mem(lst:list):
    for i in range(1000000):
        lst.append(i)
    
mem()