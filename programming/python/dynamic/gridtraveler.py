# complexity 
# tme O(m*n)
# space O(n + m)
def grid(a, b, mem):
    key = f"{a}"+','+ f"{b}"
    res = 0
    if key in mem: return mem[key]
    if a == 1 and b == 1: return 1
    if a <= 0 or b <= 0: return 0
    mem[key] = grid(a-1, b, mem) + grid(a, b - 1, mem)
    return  mem[key]

mem = {}
print(grid(1, 1, mem))
print(grid(2, 3, mem))
print(grid(3, 3, mem))
print(grid(18, 18, mem))

#complexity
# time O(2**(m+n))
# space O(m + n)
def gridbrute(a, b):
    key = f"{a}"+','+ f"{b}"
    res = 0
    if a == 1 and b == 1: return 1
    if a <= 0 or b <= 0: return 0
    tmp = gridbrute(a-1, b) + gridbrute(a, b-1)
    return  tmp

print(gridbrute(1, 1))
print(gridbrute(2, 3))
print(gridbrute(3, 3))
print(gridbrute(18, 18))