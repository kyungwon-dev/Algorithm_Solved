import re

def solution(my_string):
    my_string = my_string.strip()
    answer = re.split("\s+", my_string)
    return answer