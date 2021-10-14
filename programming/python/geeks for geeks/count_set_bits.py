def countSetBits(n):

    ans = 0
    x = 1

    while(x <= n):
        x = x*2
        print(x)
        quotient = (n+1)//x
        remainder = (n+1) % x
        total = quotient*(x//2)
        print(quotient)
        print(remainder)

        if remainder > (x//2):
            total += remainder-x//2
        ans += total
    return ans


print(countSetBits(10))
