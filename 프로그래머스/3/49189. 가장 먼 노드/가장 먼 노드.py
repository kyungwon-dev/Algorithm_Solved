from collections import deque
def solution(n, edge):
    answer = 0
    
    # 노드 간의 거리 -> BFS로 접근
    
    visited = [0 for _ in range(n)] # 0: 방문안함 , 0> : 1번 노트로부터의 거리
    edge_dict = {
        i : [] for i in range(n)
    } # 노드 간 간선 저장
    
    for e in edge:
        edge_dict[e[0]-1].append(e[1]-1)
        edge_dict[e[1]-1].append(e[0]-1)
    
    # print(edge_dict)
    
    dq = deque([])
    dq.append(0) # 시작위치
    visited[0] = 1 # 시작위치. 1번노드는 방문처리를 위해 1로 설정
    dist = 1
    while dq:
        # print(dq)
        # print(visited)
        q_length = len(dq)
        for i in range(q_length):
            s_node = dq.popleft() # O(1)
            for e in edge_dict[s_node]:
                if visited[e] == 0:
                    dq.append(e)
                    visited[e] = dist
        dist +=1

    visited[0] = 0 # 시작위치이므로 실질적인 거리는 0
    visited.sort(reverse=True)
    for i in range(1, len(visited)):
        if visited[0] == visited[i]:
            answer+=1
    
    return answer+1