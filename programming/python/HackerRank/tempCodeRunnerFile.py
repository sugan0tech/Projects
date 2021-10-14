def fun(i:int, j:int, lst:list) -> int:
    tmp = list.copy(lst)
    tmp[i] = 2**25 - 1
    tmp[j] = 2**25 - 1
    res = tmp[0]

    for i in tmp:
        res = res&i
    return res
var = 2**25 - 1

def do(lst, n):
    res = 0
    for i in range(n):
        for j in range(i, n):
            res += fun(i, j, lst)

    res -= fun(0, n - 1, lst)
    return res


T = int(input())
while T:
    n = int(input())
    tmp = str(input())
    lst = list(map(int, tmp.split()))
    print(do(lst, n))
    
    T -= 1