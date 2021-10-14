def chekc(st : str) -> bool:
    if st[::-1] != st:
        return False
    vowvels = "aeiou"
    for i in range(len(st) - 1):
        if (st[i] in vowvels)and(st[i + 1] in vowvels) :
            return False
    return True

def printAllKLength(set, k):
    n = len(set)
    printAllKLengthRec(set, "", n, k)
 
def printAllKLengthRec(set, prefix, n, k):
    if (k == 0) :
        result.append(prefix)
        return
    for i in range(n):
        newPrefix = prefix + set[i]
        printAllKLengthRec(set, newPrefix, n, k - 1)

set1 = []
letters = "abcdefghijklmnopqrstuvwxyz"

for i in letters:
    set1.append(i)

n = int(input())
for i in range(n):
    result = []
    t = int(input())
    printAllKLength(set1, t)
    end = []
    for i in result:
        if chekc(i):
            end.append(i)
    print(len(end))
