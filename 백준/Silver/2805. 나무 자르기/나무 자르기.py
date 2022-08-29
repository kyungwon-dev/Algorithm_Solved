import sys
import bisect
N, M = map(int, sys.stdin.readline().strip().split())
trees = list(map(int, sys.stdin.readline().strip().split()))
trees.sort()
left, right = 0 , trees[-1]
while left <= right:
    mid = (left + right) // 2
    take_trees = sum(map(lambda x: 0 if x< mid else x-mid, trees))
    if take_trees >= M:
        left = mid + 1
    else:
        right = mid - 1
print( (left+right) // 2)