import sys
total = int(sys.stdin.readline().strip())
N = int(sys.stdin.readline().strip())
bill = []
for i in range(N):
    nums = list(map(int, sys.stdin.readline().strip().split()))
    bill.append(nums[0] * nums[1])
if total == sum(bill):
    print("Yes")
else:
    print("No")