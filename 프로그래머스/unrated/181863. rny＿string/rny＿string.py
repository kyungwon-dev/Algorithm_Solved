def solution(rny_string):
    answer = "".join(list(map(lambda x : "rn" if x == "m" else x, list(rny_string))))
    return answer