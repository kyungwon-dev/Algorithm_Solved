def solution(n, times):
    times.sort()
    left, right = times[0], times[-1] * n
    answer = times[-1] * n
    
    while left <= right:
        mid = (left + right) // 2
        
        people = 0
        for time in times:
            people += mid // time
        
        if people >= n:
            right = mid -1
            answer = min(answer, mid)
        else:
            left = mid + 1

    return answer