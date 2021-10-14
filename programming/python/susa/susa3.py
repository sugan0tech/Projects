def pytha(n: int) -> int :
    A = []
    res = []
    for i in range(n + 1):
        A.append(i)
    size = len(A)
    for i in range(0, size - 2):
        for j in range(i + 1, size - 1):
            for k in range(j + 1, size):
                if A[i]**3 + A[j]**2 == A[k]**2:
                    res.append((A[i], A[j], A[k]))
    A = 0
    B = 0
    for i in res:
        A += i[0]
        B += i[1]
    return A + B
print(pytha(100))
                    


