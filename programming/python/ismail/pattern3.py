num=int(input("Enter a number:"))
for i in range(num):
    for j in range(num-i-1):
        print(end=" ")
    for j in range (i+1):
        print("*",end="")
    print()