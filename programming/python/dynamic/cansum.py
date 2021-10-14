#cansum 
#return bool whether the targetsum can be formed
#we can use an element of the array as many time as needed
#all elements of the array non negative

#brtuforce solution
#n = lenght of array, m = number
#complexity n**m
#space complexity m
def cansumb(target : int, arr: list) -> bool:
    if target == 0 : return True;
    if target < 0 : return False;
    for i in arr:
        reminder = target - i
        if(cansumb(reminder, arr)) == True : return True;
    
    return False;

#time  complexity O(n * m)
#space complexity O(m)
# m = number, n = size of array
def cansumo(target : int, arr: list, memo:hash) -> bool:
    if target in memo:
        return memo[target]
    if target == 0 : return True;
    if target < 0 : return False;
    for i in arr:
        reminder = target - i
        if(cansumo(reminder, arr, memo)) == True :
            memo[target] = True
            return True
    
    memo[target] = False
    return False

print(cansumo(7, [5, 3, 4, 7], {}))#true
print(cansumo(7, [2, 4], {}))#false
print(cansumo(300, [7, 14], {}))#false