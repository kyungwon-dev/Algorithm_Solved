from collections import deque
def solution(n, roads, sources, destination):
    answer = []
    dq = deque()
    
    edge_dict = {
        i : [] for i in range(n+1)
    }
    for road in roads:
        s, d = road
        edge_dict[s].append(d)
        edge_dict[d].append(s)
    
    # print(edge_dict)
    
    visited = [-1 for _ in range(n+1)] # -1 : 방문 안함
    dq.append(destination)
    visited[destination] = 0
    while dq:
        s = dq.popleft()
        for e in edge_dict[s]:
            if visited[e] >= 0:
                continue
            dq.append(e)
            visited[e] = visited[s] + 1
    # print(visited)    
    for source in sources:
        answer.append(visited[source])
    
    return answer