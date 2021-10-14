def long_not_repeat(s):
    p1 = 0
    p2 = 1
    val = ""
    while p2 < len(s) and p1 < p2:
        print(val)
        if s[p2] in val:
            p1 += 1
        elif s[p1] == s[p2]:
            p1 += 1
            p2 += 1
        else:
            if (p2 - p1) > len(val) and s[p1] != s[p2]:
                val = s[p1:p2 + 1]
            p2 += 1
    return len(val)

s = "bbbbbbb"
print(long_not_repeat(s))