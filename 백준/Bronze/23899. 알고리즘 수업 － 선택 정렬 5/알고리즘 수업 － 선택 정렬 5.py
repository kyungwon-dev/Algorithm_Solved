import sys
from collections import deque
sys.setrecursionlimit(10**5)

N = int(sys.stdin.readline().strip())
nums = list(map(int, sys.stdin.readline().strip().split()))
target = list(map(int, sys.stdin.readline().strip().split()))
num_dict = {k:v for k,v in zip(nums, range(len(nums)))}
nums_sort = sorted(nums)
is_equal = 0

for i in range(N-1, 0, -1):
    if nums == target:
        is_equal = 1
        break
    if nums[i] != nums_sort[i]:
        tmp = nums[i]
        nums[i], nums[num_dict[nums_sort[i]]] = nums[num_dict[nums_sort[i]]], nums[i]
        num_dict[tmp], num_dict[nums[i]] = num_dict[nums[i]] ,num_dict[tmp]
    if nums == target:
        is_equal = 1
        break
print(is_equal)
        