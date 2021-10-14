def pytha(n: int) ->int:
    A = 0
    B = 0
    for i in range(n):
        for j in range(n):
            for k in range(n):
                if i**3 + j**2 == k**2:
                    print(i, j, k)
                    A += i
                    B += j
    return A + B

prin(pytha(10))
