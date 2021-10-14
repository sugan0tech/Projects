a=int(input("english:"))
b=int(input("tamil:"))
c=int(input("maths:"))
d=int(input("physics:"))
e=int(input("chemistry:"))
f=int(input("biology:"))
tot=a+b+c+d+e+f
print("total:",tot)
per=(tot/600)*100
print("percentage=",per)
if per>90:
    print("1st class")
    if per==100:
        print("distinction")
elif per<82 and per>=70:
    print("2nd class")
elif per<68 and per>=50:
    print("3rd class")
else:
    print("no class ")
    print ("try harder")
