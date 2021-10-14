def findMean(arr, queries, n, q):
    prefix = [0 for i in range(n)]
    prefix[0] = arr[0]
    for i in range(1, n):
        prefix[i] = prefix[i - 1] + arr[i]

    
    res = []
    
    def mean(l, r):
        if l == 0:
            return int(prefix[r]/(r + 1))
        temp = (prefix[r] - prefix[l - 1])/(r - l + 1)
        
        return int(temp)
        
    for i in range(0, q, 2):
        if i + 1 < q:
            res.append(mean(queries[i], queries[i + 1]))
    return res
print(findMean([1, 2, 3, 4, 5], [0, 2, 1, 3, 0, 4], 5, 6))