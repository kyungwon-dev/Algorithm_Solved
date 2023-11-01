def solution(str1, str2):
    if len(str1) > len(str2) or str1 not in str2:
        return 0
    return 1