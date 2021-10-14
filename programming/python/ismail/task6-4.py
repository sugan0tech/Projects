def check(a):
    b=a[-1::-1]
    print("string: ",a)
    print("reverse: ",b)
    if(a==b):
        return True
    else:
        return false
x=input("Enter a string:")
if check(x):
    print("it is palindromic")
else:
    print("it is not palindromic")