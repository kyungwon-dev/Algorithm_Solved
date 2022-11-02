import sys
from collections import deque
sys.setrecursionlimit(10**5)

N, K = list(map(int, sys.stdin.readline().strip().split()))
nums = list(map(int, sys.stdin.readline().strip().split()))
num_dict = {k:v for k,v in zip(nums, range(len(nums)))}
nums_sort = sorted(nums)

change = 0
idx = K-1
rs = ""
for i in range(N-1, 0, -1):

    if nums[i] != nums_sort[i]:
        tmp = nums[i]
        change+=1
        nums[i], nums[num_dict[nums_sort[i]]] = nums[num_dict[nums_sort[i]]], nums[i]
        num_dict[tmp], num_dict[nums[i]] = num_dict[nums[i]] ,num_dict[tmp]
        if change == K:
            rs = " ".join(map(str, nums))
            break
if rs == "":
    print(-1)
else:
    print(rs)
        