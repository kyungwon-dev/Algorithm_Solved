import sys
from collections import deque
from bisect import bisect_left
sys.setrecursionlimit(10**5)

# input
N = int(sys.stdin.readline().strip())
nums = list(map(int,sys.stdin.readline().strip().split()))
dist = [1]
lis = [nums[0]]
for i in range(1, N):
    if lis[-1] < nums[i]:
        # add
        lis.append(nums[i])
        dist.append(len(lis))
    else:
        # substitute
        sub = bisect_left(lis, nums[i])
        lis[sub] = nums[i]
        dist.append(sub+1)
target = len(lis)
print(target)
rs = []
for i in range(N-1, 0-1, -1):
    if dist[i] == target:
        rs.append(nums[i])
        target-=1
for i in range(len(rs)-1, 0-1, -1):
    print(rs[i], end=" ")
print("")