# bestsum
# needed full tree exploration
def bestsum(target: int, arr: list) -> list:
    if target == 0:
        return None
    if target < 0:
        return None

    shortest_combination = None

    for i in arr:
        remainder = target - i
        remainder_combo = bestsum(remainder, arr)
        if remainder_combo != None:
            combination = remainder_combo.append(i)
            if (shortest_combination is None) or (len(combination) < len(shortest_combination)):
                shortest_combination = combination

    return shortest_combination


print(bestsum(8, [2, 3, 5]))
