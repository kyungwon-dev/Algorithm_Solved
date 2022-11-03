import sys
from collections import deque
from bisect import bisect_left
sys.setrecursionlimit(10**5)

# input
N, M = list(map(int, sys.stdin.readline().strip().split()))
arrs = [list(map(int, sys.stdin.readline().strip().split())) for _ in range(N)]

acc_sum = [[0 for _ in range(M+1)] for _ in range(N+1)]

for i in range(1,N+1):
    for j in range(1,M+1):
        acc_sum[i][j] = acc_sum[i-1][j] + acc_sum[i][j-1] + arrs[i-1][j-1] - acc_sum[i-1][j-1]
        
K = int(sys.stdin.readline().strip())

for i in range(K):
    sy,sx,dy,dx = list(map(int, sys.stdin.readline().strip().split()))
    print( acc_sum[dy][dx] - acc_sum[sy-1][dx] - acc_sum[dy][sx-1] + acc_sum[sy-1][sx-1])
    