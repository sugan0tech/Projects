def calculaterange(a,b,i):
    if i in range (a,b):
        print("yes within the given range")
    else:
        print("no not in the given range")

a=int(input("Enter a lower limit:"))
b=int(input("Enter a upper limit:"))
i=int(input("enter a number="))
calculaterange(a,b,i)
