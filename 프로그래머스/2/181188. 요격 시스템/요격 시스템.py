def solution(targets):
    answer = 0
    targets.sort(key = lambda x : (x[0], x[1]))
    range = [-1,-1]
    # print(targets)
    for s,d in targets:
        if range[1] > s:
            if s > range[0]:
                range = [s, min(range[1], d)]
        else:
            answer+=1
            # print(range)
            range = [s,d]
    # print(range)
    return answer