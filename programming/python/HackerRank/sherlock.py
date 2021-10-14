import math


def squares(a, b):
    count = 0
    j = round(math.sqrt(a))
    for i in range(a, b+1):
        if j**2 == i:
            count+= 1            
            j += 1
        if j**2 > b:
            exit
        
    return count


print(squares(3, 9))