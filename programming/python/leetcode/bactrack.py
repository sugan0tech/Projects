def backspaceCompare(s: str, t: str) -> bool:
    
    p1 = len(s) - 1
    p2 = len(t) - 1
    count1 = 0
    count2 = 0
    while p1 >= len(s) - 1 or p2 >= len(t) - 1:
        if s[p1] == '#':
            count1 += 1
                
        if t[p2] == '#':
            count2 += 1
        
        if s[p1] != '#':
            if count1:
                p1 -= 1
        if t[p2] != '#':
            if count2:
                p2 -= 1
            
        if count1 == 0 and count2 == 0:
            if s[p1] != t[p2]:
                return 0
        p1 -= 1  
        p2 -= 1
    return 1

s = "xyrmp"
t = "xyrm#p"

print(backspaceCompare(s, t))