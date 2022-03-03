from pickle import FALSE

n = int(input())
arr = []
for i in range(n):
    arr[i] = int(input())


arr = [1, 2, 1, 4, 5]
map = {}
for i in arr:
    if(i not in map):
        map[i] = 1
    else:
        map[i] = map[i] + 1


print(map.keys(), map.values())

min_ind = 0
min = len(arr)
max_ind = 0
max = 0
count = 0
for i in map.values():
    if(i > max):
        max = i
        max_ind = count
    elif i < min:
        min = i
        min_ind = count
    count += 1

for i in map.keys():
    if(map.get(i) == min):
        minval = i
    elif(map.get(i) == max):
        maxval = i


print(abs(minval - maxval))
