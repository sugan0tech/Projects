def count_bin(n: int) -> int:
    count = 0
    while n != 0:
        if n % 2 == 1:
            count += 1
        n //= 2

    return count


def main(N: int) -> int:
    count = 0

    for i in range(N + 1):
        count += count_bin(i)

    return count


print(main(4))
