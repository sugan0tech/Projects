def setZeroes(matrix):
    m = len(matrix)
    n = len(matrix[0])
    lst1 = [0 for i in range(m)]
    lst2 = [0 for i in range(n)]
    
    for i in range(m):
        for j in range(n):
            if matrix[i][j] == 0:
                lst1[i] = 1
                lst2[j] = 1

    for i in lst1:
        if i == 1:
            matrix[lst1.index(i)] = 0
    return lst1, lst2

mat = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
print(setZeroes(mat))