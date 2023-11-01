def solution(my_string, target):
    if len(my_string) < len(target):
        return 0
    if target in my_string:
        return 1
    return 0