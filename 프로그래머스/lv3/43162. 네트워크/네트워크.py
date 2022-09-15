from collections import deque
def solution(n, computers):
    visited = [0 for _ in range(len(computers))]
    connected = 1
    for i in range(len(computers)):
        q = deque([])
        if visited[i] !=0:
            continue
            
        for j in range(len(computers[i])):
            if i==j:
                continue
            else:
                if computers[i][j] == 1:
                    q.append(j)
                    visited[j] = connected    
                            
        visited[i] = connected
        while q:
            next = q.popleft()
            for i in range(len(computers[0])):
                if computers[next][i] == 1 and visited[i] == 0:
                    q.append(i)
                    visited[i] = connected
        connected +=1
    return max(visited)