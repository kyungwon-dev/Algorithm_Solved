import sys
N = int(sys.stdin.readline().strip())
nums = []
for i in range(N):
    num = int(sys.stdin.readline().strip())
    if num == 0:
        nums.pop()
    else:
        nums.append(num)
print(f"{sum(nums)}")
