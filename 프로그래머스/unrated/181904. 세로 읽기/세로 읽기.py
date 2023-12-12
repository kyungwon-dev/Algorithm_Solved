def solution(my_string, m, c):
    answer = "".join([my_string[i] for i in range(c-1, len(my_string), m)])
    return answer