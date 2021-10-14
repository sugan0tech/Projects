import time


def timer(func):
    def warp(n, mem):
        start = time.time()
        print(func(n, mem))
        print(time.time() - start)
    return warp
# using memorisation


@timer
def sub(n, mem):
    return fib(n, mem)


def fib(n: int, mem):
    if n in mem:
        return mem[n]
    if n <= 2:
        return 1
    mem[n] = fib(n - 1, mem) + fib(n - 2, mem)
    return mem[n]


mp = {}

sub(5, mp)
