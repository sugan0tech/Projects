matrix = [[4,9],[0,2]]
flag = 0
for i in range(len(matrix)):
	for j in range(len(matrix)):
		if matrix[i][j] == 0:
			flag = 1
if flag==1:
	for i in range(len(matrix)):
		for j in range(len(matrix)):
			matrix[i][j] = 0
print(matrix)