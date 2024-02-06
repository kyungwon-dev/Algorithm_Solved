def solution(l, r):
    answer = []
    for i in range(1,64,1):
        if l <= int(bin(i)[2:])*5 <= r:
            answer.append(int(bin(i)[2:])*5)
    if not answer:
        answer.append(-1)
    
    return answer