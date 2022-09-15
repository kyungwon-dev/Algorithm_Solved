def solution(n, s):
    d = s//n
    m = s%n
    if n==1:
        return [s]
    if s==n:
        return [1 for _ in range(n)]
    if d==0:
        return [-1]
    answer = [d for _ in range(n)]

    for i in range(n -1, n - m -1, -1):
        answer[i] += 1
    
    return answer