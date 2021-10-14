#!/bin/python3

def prime(num):
    if num > 1:
        for i in range(2, num):
            if num%i == 0:
                return 0
        return 1
def spl_fib(m:int, n:int, x:int, y:int):
    tmp = 0
    for i in range(x - 1):
        tmp = n
        n = m + n
        m = tmp
        if prime(m) and m**2 > y:
            return m
    return -1

if __name__ == '__main__':
    m, n, x, y = map(int, input().split())

    print(spl_fib(m, n, x, y))