def cutTheSticks(arr):
    mn = min(arr)
    lst = []
    n = len(arr)
    while n:
        count = 0
        mn = mdn(arr)

        for i in range(len(arr)):
            if arr[i] > 0:
                if arr[i] - mn <= 0:
                    arr[i] = 0
                else:
                    arr[i] -= mn
                count += 1


        if count == 0:
            break
        lst.append(count)
        n -= 1
    return lst
               

def mdn(arr):
    lst = []
    for i in arr:
        if i > 0:
            lst.append(i)
    if len(lst) == 0:
        lst.append(0)

    return min(lst)
arr = [8, 8, 14, 10, 3, 5, 14, 12]
print(cutTheSticks(arr))