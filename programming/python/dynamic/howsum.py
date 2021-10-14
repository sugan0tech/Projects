# brutefroce solution
# m = num, n = array length
# time complexity (n^m * m)
def howsum(target, arr):
    if target == 0:
        return []
    if target < 0:
        return None

    for num in arr:
        reminder = target - num
        tmp = howsum(reminder, arr)
        if tmp != None:
            tmp.append(num)
            return tmp
    return None


print(howsum(7, [5, 3, 4, 7]))
print(howsum(8, [2, 1, 3]))
print(howsum(40, [3, 1]))
print(howsum(40, [3]))


# optimal solution
# time complexity : O(n*m^2)
# space complexity : O(m^2)
def howsumo(target, arr, memory):
    if target in memory:
        return target[memory]
    if target == 0:
        return []
    if target < 0:
        return None

    for num in arr:
        reminder = target - num
        tmp = howsumo(reminder, arr, memory)
        if tmp != None:
            tmp.append(num)
            memory[target] = tmp
            return memory[target]
    memory[target] = None
    return None


print(howsumo(7, [5, 3, 4, 7], {}))
print(howsumo(8, [2, 1, 3], {}))
print(howsumo(40, [3, 1], {}))
print(howsumo(300, [3], {}))
