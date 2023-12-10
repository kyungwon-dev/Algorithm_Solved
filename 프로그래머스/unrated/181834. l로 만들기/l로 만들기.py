def solution(myString):
    answer = "".join(list(map(lambda x : x if ord(x) >= ord('l') else 'l', myString)))
    return answer