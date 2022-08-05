nums = [int(x) for x in input().split()]
nums = sum(map(lambda x : x**2, nums)) % 10
print(nums)
