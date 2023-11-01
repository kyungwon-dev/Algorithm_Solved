def solution(my_strings, parts):
    answer = ""
    for my_string, part in zip(my_strings, parts):
        answer = answer + my_string[part[0]:part[1]+1]
    return answer