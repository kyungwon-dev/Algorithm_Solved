import sys
import collections, bisect, heapq
# setting
sys.setrecursionlimit(10**5)
input = sys.stdin.readline
max_inf = sys.maxsize

N = int(input().strip())
E = int(input().strip())

distance = [max_inf for _ in range(N+1)]
adj_list = [[] for _ in range(N+1)]

for i in range(E):
    s, d, p = list(map(int,input().strip().split()))
    adj_list[s].append( (p,d))
start, destination = list(map(int, input().strip().split()))

def dijkstra(start):
    q= []
    heapq.heappush(q, (0, start))
    distance[start] = 0
    while q:
        dist , node = heapq.heappop(q)
        if distance[node] < dist:
            continue
        
        for next in adj_list[node]:
            cost = distance[node] + next[0]
            
            if cost < distance[next[1]]:
                distance[next[1]] = cost
                heapq.heappush(q, (cost, next[1]))
        
dijkstra(start)
print(distance[destination])
