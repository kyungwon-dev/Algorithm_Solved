import sys
import collections, bisect, heapq, itertools
# setting
sys.setrecursionlimit(10**5)
input = sys.stdin.readline
max_inf = sys.maxsize

N = int(input().strip())
M = int(input().strip())
adj_matrix = [[max_inf for _ in range(N+1)] for _ in range(N+1)]
for i in range(M):
    start, dest, cost = map(int, input().strip().split())
    if adj_matrix[start][dest] == max_inf:
        adj_matrix[start][dest] = cost
    else:
        adj_matrix[start][dest] = min(cost, adj_matrix[start][dest])
        
for i in range(1, N+1): # 거쳐가는 노드
    for j in range(1, N+1): # 출발 노드
        for k in range(1, N+1): # 도착 노드
            if j==k:
                adj_matrix[j][k] = 0
                continue
            if adj_matrix[k][i] != max_inf or adj_matrix[i][j] != max_inf:
                adj_matrix[k][j] = min(adj_matrix[k][j], adj_matrix[k][i] + adj_matrix[i][j])
for i in range(1, N+1):
    for j in range(1, N+1):
        print(adj_matrix[i][j] if adj_matrix[i][j] < max_inf else 0, end=" ")
    print("")