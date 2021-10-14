def solution(A : [int], size : int) -> int:
    boo = True
    while boo:
        small = min(A)
        big = max(A)
        if small%2 == 1:
            A.remove(small)
        if big%2 == 1:
            A.remove(big)
        if (small%2 == 0) and (big%2 == 0):
            return small + big


print(solution([1, 2, 5, 6, 8], 5))