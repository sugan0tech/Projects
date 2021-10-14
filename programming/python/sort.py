import time
def timer(func):
    def warper():
        initial = time.time()
        func()
        print("The time taken is " , time.time() - initial)
    return warper

def quickstart(lst : list) -> list:
    if len(lst) < 2:
        return lst
    pivot = lst[0]
    less = [i for i in lst[1:] if i < pivot]
    greater = [i for i in lst[1:] if i > pivot]

    return quickstart(less) + [pivot] + quickstart(greater)


@timer
def func():
    lst = [i for i in range(100)]
    lst.sort(reverse=True)
    print(quickstart(lst))

func()