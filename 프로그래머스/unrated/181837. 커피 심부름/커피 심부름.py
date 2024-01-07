def solution(order):
    answer = sum([5000 if "cafelatte" in o else 4500 for o in order])
    return answer