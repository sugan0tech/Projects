import time
def timer(func):
    def warper():
        before = time.time()
        func()
        print("time taken", time.time() - before)
    return warper

def func(f):
    def warp():
        print("------")
        f()
        print("------")

    return warp
    
@timer
@func
def function():
    for i in range(100):
        pass
    print("done")

function()

def allfun(*args, **kwargs):
    # this is the function wich accepts all the kind of argiuments and kyword arguments
    print(*args, **kwargs)

allfun(1, 2, 3, 4)
def gen():
    for i in range(10):
        yield i

gen()



print("-------------------------------------------------")

def war(func):
    var = func("hi")
    print(var)

def test1(var):
    return var

war(test1)

def gfg_decorator(func):
    return
@gfg_decorator
def hello_decorator():
    print("Gfg")

'''Above code is equivalent to -

def hello_decorator():
    print("Gfg")
    
hello_decorator = gfg_decorator(hello_decorator)'''