from collections import deque
import sys

N, M, K , X = map(int, sys.stdin.readline().strip().split())
graph = {k:[] for k in range(1, N+1)}
for i in range(M):
    v, e = map(int, sys.stdin.readline().strip().split())
    graph[v].append(e)
is_visit = [0]*(N+1)
is_visit[X] = -1
distance = 1
bfs = deque([X])
while len(bfs) > 0:
    loop = len(bfs)
    for i in range(loop):
        v = bfs.popleft()
        for e in graph[v]:
            if is_visit[e] == 0:
                bfs.append(e)
                is_visit[e] = distance
    
    distance +=1
not_distance = False
for vertex,distance in enumerate(is_visit):
    if distance == K:
        print(vertex)
        not_distance = True
if not_distance == False:
    print("-1")