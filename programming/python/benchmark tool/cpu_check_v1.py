import time
import multiprocessing

res = []
def timer(func):
    def warper():
        before = time.time()
        func()
        res.append(time.time() - before) 
    return warper

@timer
def function():
    for i in range(10):
        print(f"{i}\r", end="")
        pass

count = 0
tot = 0

while count < 10:
    try:
        proceses = []
        for i in range(100):
            p = multiprocessing.Process(target = function())
            proceses.append(p)
            p.start()
            count+= 1

        for process in proceses:
            process.join()

    except:
        print("Error")
        break

for i in res:
    tot += i
print(f"Count {count}, time {tot}")
if count != 0:
    print("Average " , tot/count)