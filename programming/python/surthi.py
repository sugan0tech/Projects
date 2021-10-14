V=  str(input())
List=[] 
N = int(input()) # for number of people
for i in range(N): 
    z=input() 
    List.append(z) 
for i in List: 
    for j in i: 
        if j in V: 
            print("POSITIVE")
        else: 
            print("NEGATIVE")  