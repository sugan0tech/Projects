import time
def timer(func):
    def magic(a, b):
        func(a, b)
    return magic

@timer
def fun(a, b):
    print("done")
    while b:
        b -= 1
    return a + b


fun(1, 3)