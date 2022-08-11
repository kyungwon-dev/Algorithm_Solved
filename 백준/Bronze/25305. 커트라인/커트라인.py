import sys
N, K = map(int, sys.stdin.readline().strip().split())
nums = sorted(list(map(int, sys.stdin.readline().strip().split())),reverse=True)
print(nums[K-1])
