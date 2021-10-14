
def gen(n):
    for i in range(n):
        yield i**2

#yield is similar to return 
"""instead of stoping entire function (in return ) , yield works over iteration each iteration return one at a time"""
g = gen(100)
print(next(g))
print(next(g))
print(next(g))
print(next(g))
print(next(g))
print(next(g))
print("-------")

for i in g:
    print(i)

"""Note this thing have lot more than next() ---> stop , input etc..
print"""