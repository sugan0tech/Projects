# Write your code here
def sensor1(n: int) -> list:
    lst = [1]
    temp = 1
    for i in range(n):
        temp *= 2
        for i in range(int(temp/2)):
            if len(lst) < n:
                lst.append(temp)
            if len(lst) > n:
                return lst
    return lst

def sensor2(n:int, x:int) -> list:
    temp = x
    lst = []
    for i in range(n):
        if True:
            for i in range(x):
                if len(lst) < n:
                    lst.append(temp)
        temp += x
    lst.sort()
    return lst

def solution(l, r, x):
    lst1 = sensor1(r)
    lst2 = sensor2(r, x)
    lst1v = 0
    lst2v = 0
    for i in range(l - 1, r):
        if lst1[i] < lst2[i]:
            lst1v += 1
        if lst1[i] > lst2[i]:
            lst2v += 1
    if lst1v > lst2v:
        return 1
    elif lst2v > lst1v:
        return 2
    else :
        return 0

n = int(input())
for i in range(n):
    l, r, x = input().split()
    print(solution(int(l), int(r), int(x)))
