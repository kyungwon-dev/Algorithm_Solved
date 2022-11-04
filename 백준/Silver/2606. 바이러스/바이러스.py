import sys
from collections import deque
from bisect import bisect_left
sys.setrecursionlimit(10**5)

# input
N = int(sys.stdin.readline().strip()) # computer 
graph = {k+1:[] for k in range(N)} # graph
visited = [False for _ in range(N+1)]
V = int(sys.stdin.readline().strip())
for i in range(V):
    start, dest = list(map(int, sys.stdin.readline().strip().split()))
    graph[start].append(dest)
    graph[dest].append(start)

start = 1
q = deque([])
q.append(start)
visited[start] = True
while q:
    node = q.popleft()
    for g in graph[node]:
        if not visited[g]:
            q.append(g)
            visited[g] = True

print(sum(visited) -1)
    
