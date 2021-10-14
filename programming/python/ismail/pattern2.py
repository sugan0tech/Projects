a=int(input("enter a number="))
for i in range (a):
    for j in range (i+1):
        if j==3:
            continue
        print(j,end=" ")
    print()
