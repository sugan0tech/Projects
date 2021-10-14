def strange_sum(L, R):
    def prime(n):
        i = 2
        num = n
        while i < num:
            if num % i == 0:
                return False
                break
            else:
                i = i + 1

        else:
            return True

    def factors(num):
        list2 = []
        n = num
        for i in range(n):
            if n % (i + 1) == 0:
                list2.append(i + 1)
        return list2

    def two_val(var1):
        list3 = factors(var1)
        list3.remove(var1)
        for i in list3:
            for j in list3:
                if i * j == var1:
                    temp = []
                    if i <= j:
                        temp.append(i)
                        temp.append(j)
                        return tuple(temp)

    def check(var):
        if var == 1:
            return 0
        elif prime(var) == True:
            return 1
        else:
            x, y = two_val(var)
            res = x * check(y) + y * check(x)
            return res

    t = 0
    for i in range(L, R + 1):
        list1 = factors(i)
        s = 0
        for j in list1:
            s += int(check(j))
        t += s
    return t


T = int(input())
for _ in range(T):
    L, R = input().split()
    L = int(L)
    R = int(R)
    out_ = strange_sum(L, R)
    print(out_)








