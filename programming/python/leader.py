arr = [1, 2, 3, 4, 1, 3, 6, 6, 7, 8, 9, 2, 3]
tmp = []
hsh = {}

for i in arr:
    if i not in hsh:
        hsh[i] = 1
    else:
        tmp.append(i)

for i in arr:
    if i not in tmp:
        print(i)
