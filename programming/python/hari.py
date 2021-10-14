def rotate(r,n, lst: list):
    res = []
    for i in range(r, n):
        res.append(lst[i])
    for i in range(r):
        res.append(lst[i])
    
    return res
    
N = int(input())
while N:
    n, r = list(map(int, input().split()))
    arr = list(map(int, input().split()))
    print(rotate(r, n, arr))
    N -= 1