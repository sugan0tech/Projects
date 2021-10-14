name=input("enter a name=")
length=len(name)
for i in range(length):
    for j in range(length-i):
        print(name[j],end="  ")
    print()

for i in range(length):
    for j in range(i+1):
        print(name[j],end="  ")
    print()