def solution(q, r, code):
    answer = "".join([code[i] if i%q == r else "" for i in range(len(code)) ])
    return answer