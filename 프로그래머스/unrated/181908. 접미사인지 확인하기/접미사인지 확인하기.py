def solution(my_string, is_suffix):
    if len(my_string) < len(is_suffix):
        return 0
    
    return 1 if my_string[-len(is_suffix):] == is_suffix else 0