def median(ar1, ar2):
    ar1 = ar1 + ar2
    ar1.sort()
    n = len(ar1)
    if n%2 == 0:
        tmp = (ar1[n//2 - 1] + ar1[n//2])/2
        ck = (ar1[n//2 - 1] + ar1[n//2])//2
        if tmp > ck:
            return tmp
        else:
            return ck
    else:
        return ar1[n//2]



arr1 = [1, 2]
arr2 = [3, 4]

print(median(arr1, arr2))