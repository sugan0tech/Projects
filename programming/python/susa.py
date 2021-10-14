arr = [ 2, 3, 4, 5, 8, 12]
n = 6
i = 0

set = {}

for i in arr:
    for j in arr:
        for k in arr:

            if abs(i - j) == abs(i - k):
                set.add([i, j, k])

print(set)