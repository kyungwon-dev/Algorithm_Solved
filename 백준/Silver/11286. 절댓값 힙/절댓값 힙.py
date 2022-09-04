import sys
import heapq
n = int(sys.stdin.readline().strip())
nums = []
for i in range(n):
    
    num = int(sys.stdin.readline().strip())
    if num != 0:
        heapq.heappush(nums, (abs(num), num))
    else:
        if nums:
            print(heapq.heappop(nums)[1])
        else:
            print(0)
