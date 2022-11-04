import sys
import collections, bisect, heapq
# setting
sys.setrecursionlimit(10**5)
input = sys.stdin.readline

# input
V, E = map(int , input().strip().split())

adj_list = [[] for _ in range(V)]
max_inf = sys.maxsize
distance = [max_inf for _ in range(V)]

start = int(input().strip()) - 1
for i in range(E):
    n1, n2, prior = map(int , input().strip().split())
    n1, n2 = n1-1, n2-1
    adj_list[n1].append((prior, n2))

# dijkstra
def dijkstra(start):
    q = []
    heapq.heappush(q, (0, start))
    distance[start] = 0
    while q:
        dist, dest = heapq.heappop(q)

        if distance[dest] < dist:
            continue
        
        for next in adj_list[dest]:
            cost = distance[dest] + next[0]
            if cost < distance[next[1]]:
                distance[next[1]] = cost
                heapq.heappush(q, (cost, next[1]))
            
dijkstra(start)
print("\n".join(list( map(lambda x : "INF" if x==max_inf else str(x), distance) )))