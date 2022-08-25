import sys
N ,M = map(int, sys.stdin.readline().strip().split())
acc_sum = [[0] * (N+1) for _ in range(N+1)]
for i in range(N):
    nums = list(map(int, sys.stdin.readline().strip().split()))
    for j in range(len(nums)):
        acc_sum[i+1][j+1] = acc_sum[i][j+1] + nums[j] + acc_sum[i+1][j] - acc_sum[i][j]
for i in range(M):
    y1, x1, y2, x2 = map(int, sys.stdin.readline().strip().split())
    rs = acc_sum[y2][x2] - acc_sum[y1-1][x2] - acc_sum[y2][x1-1] + acc_sum[y1-1][x1-1]
    print(rs)

