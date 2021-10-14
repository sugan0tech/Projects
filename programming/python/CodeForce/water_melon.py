def find(n):
    if n == 2:
        return "NO"
    elif n%2 == 0:
        return "YES"
    else:
        return "NO"

w = int(input())

print(find(w))