def solution(intStrs, k, s, l):
    intStrs = [ strs[s:s+l] for strs in intStrs]
    answer = []
    for strs in intStrs:
        if int(strs) > k:
            answer.append(int(strs))
    return answer