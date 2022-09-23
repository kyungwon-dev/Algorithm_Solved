
def solution(info, edges):
    answer = 0
    info_graph = {k:[] for k in range(len(info))}
    for edge in edges:
        info_graph[edge[0]].append(edge[1])
        # info_graph[edge[1]].append(edge[0])
    cand = []
    visited = [False for _ in range(len(info))]
    visited[0] = True
    def recur(start, next_cand, rs, w, s):
        if w>=s and s!=0:
            cand.append(rs[:])
            return
        if len(rs) == len(info):
            cand.append(rs[:])
            return
        for i in range(len(next_cand)):
            if visited[next_cand[i]] == False:
                visited[next_cand[i]] = True
                next_c = next_cand[:]
                next_c.extend(info_graph[next_cand[i]])
                rs.append(next_c.pop(i))
                if info[next_cand[i]] == 0:
                    s+=1
                else:
                    w+=1
                recur(start, next_c, rs, w, s)
                visited[next_cand[i]] = False
                rs.pop()
                if info[next_cand[i]] == 0:
                    s-=1
                else:
                    w-=1
                
    recur(0, info_graph[0][:], [0], 0, 1)

    for c in cand:
        s, w = 0, 0
        for i in c:
            if info[i] == 0:
                s+=1
            else:
                w+=1
            if w == s:
                break
            answer = max(answer, s)

    return answer