import heapq
def solution(n, costs):
    answer = 0
    visited = [False for _ in range(n)]
    graph = {i:[] for i in range(n)}
    
    bridges = []
    for cost in costs:
        graph[cost[0]].append([cost[2], cost[1]])
        graph[cost[1]].append([cost[2], cost[0]])
        # heapq.heappush(bridges, (cost[2], cost))
    # print(graph)
    if not cost:
        return 0
    start = 0
    visited[start] = True
    candidate = graph[start]
    heapq.heapify(candidate)
    while candidate:
        w, v = heapq.heappop(candidate)
        if visited[v] == False:
            visited[v] = True
            answer += w
            for e in graph[v]:
                if visited[e[1]] == False:
                    heapq.heappush(candidate, e)
    
    
    return answer