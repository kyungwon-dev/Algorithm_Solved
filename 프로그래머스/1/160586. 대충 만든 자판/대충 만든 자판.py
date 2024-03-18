def solution(keymap, targets):
    answer = []
    for target in targets:
        sum = 0
        for t in list(target):
            idx = 101
            for k in keymap:
                try:
                    idx = min(idx, k.index(t))
                except ValueError:
                    pass
            if idx == 101:
                sum = -1
                break
            else:
                sum += (idx+1)
        
        answer.append(sum)
        
    return answer