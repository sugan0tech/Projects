import time
def timer(fun, a, b):
    x = time.time()
    fun(a, b)
    print(time.time() - x)

def fun(a, b):
    print("done")
    while b:
        b -= 1
    return a + b

timer(fun, 1, 1000000)
