def do(mat:list, i:int, j:int) -> list:
    for a in range(len(mat[0])):
        mat[i][a] = 0

    for b in range(len(mat)):
        mat[j][b] = 0

    return mat

mat = [[1, 9], [0, 3], [1, 6]]

m = len(mat[0])
n = len(mat)
boo = 0
print(m, n)
for i in range(m):
    for j in range(n):
        print(i, j, mat[j][i])
        if mat[j][i] == 0:
            temp = i
            break
    else:
        continue
    break


temp = i
for i in range(m):
    mat[j][i] = 0

for j in range(n):
    mat[j][temp] = 0
    
for i in range(n):
    print(mat[i])
print(mat)