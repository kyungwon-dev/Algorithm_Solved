def solution(my_string, indices):
    answer = ''
    indices.sort()
    idx = 0
    for i in range(0, len(my_string)):
        if len(indices) != idx and indices[idx] == i:
            idx += 1
            continue
        answer += my_string[i]
    return answer