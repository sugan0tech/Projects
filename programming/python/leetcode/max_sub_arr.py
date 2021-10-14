def maxSubArray(nums : list[int]) -> int:
    max = min(nums)
    n = len(nums)
    for i in range(n):
        for j in range(i - 1, n):
            lst = []
            temp = 0
            boo = 0
            for k in range(i, j + 1):
                temp += nums[k]
                boo = 1
            if temp > max and boo:
                max = temp
    
    return max

lst = [-1, -2]
print(maxSubArray(lst))