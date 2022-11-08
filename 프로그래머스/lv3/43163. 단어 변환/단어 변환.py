from collections import deque

def solution(begin, target, words):
    answer = 0
    q = deque([begin])
    visited = [False for _ in range(len(words))]
    
    def distance(prev, next):
        flag = 0
        for p, n in zip(prev, next):
            if p != n:
                flag+=1
            if flag > 1:
                return False
        return True
    
    while q:
        loop = len(q)
        answer +=1
        for i in range(loop):
            prev = q.popleft()
            for j in range(len(words)):
                if visited[j] == False and distance(prev, words[j]):
                    q.append(words[j])
                    visited[j] = True
                    if words[j] == target:
                        return answer
    return 0