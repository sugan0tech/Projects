def querySum(n, arr, q, queries):
    p = [0 for i in range(n + 1)]
    p[0] = arr[0]
    print(list(enumerate(arr)))
    for i in range(1, n):
        p[i] = p[i - 1] + arr[i]
    
    print(p)
    res = []
    for i in range(0, q, 2):
        print(res)
        tmp = p[queries[i + 1]] - p[queries[i]]
        res.append(tmp)
        
    return res


arr = [1, 2, 3, 4]
queries = [1, 4, 2, 3]

print(querySum(4, arr, 2, queries))