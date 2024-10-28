
def solution(diffs, times, limit):
    answer = max(diffs)
    
    time_min = limit
    # 이분탐색을 통해 적절한 난이도 값을 찾기.
    l, r = 1, max(diffs)
    while l <= r:
        level = (l+r) //2
        
        time_cur = 0
        for i in range(len(diffs)):
            if level >= diffs[i]:
                time_cur += times[i]
                
            else:
                time_cur += (diffs[i] - level) * (times[i] + (0 if i-1<0 else times[i-1])) + times[i]
        
        # print(l, r, level, answer, time_cur)
        if time_cur > time_min:
            l = level + 1
        else:
            answer = min(level, answer)
            r = level - 1
    
    return answer