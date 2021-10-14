def good_score(s: str) -> int:
    global lst
    lst = []
    res = 0
    n = len(s) - 1
    mid = n//2 + 1

    for i in range(mid):
        if s[i] != s[n - i]:
            res += 1
        elif i != n - i:
            lst.append(i)

    return res

def brute(k:int, s:str) -> int:
    res = 0
    if good_score(s) == k:
        return res
    else :
        temp = k - good_score(s)
        for i in lst:
            res += 1
            if res == temp:
                return res
        


n = int(input())
for i in range(1, n + 1):
    K = int(input("").split()[1])
    S = str(input())
    print(f"Case #{i}:", brute(K, S))
