def prime(rnge, mem):
    mem[1] = 0
    for num in range(rnge):
        if num > 1:
            for i in range(2,num):
                if num%i == 0:
                    mem[num] = 0
                    break
            else:
                mem[num] = 1
def spl_fib(m:int, n:int, x:int, y:int, map):
    tmp = 0
    for i in range(x - 1):
        tmp = n
        n = m + n
        m = tmp
        if (map[m] == 1) and m**2 > y:
            return m
    return -1

mem = {}
m, n, x, y = map(int, input().split())
prime(x, mem)

print(spl_fib(m, n, x, y, mem))