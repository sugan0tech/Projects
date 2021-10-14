def myfunc(n):
    return abs(n - 50)



mylst = [100, 50, 65, 82, 23]
mylst.sort(key = myfunc)
print(mylst)