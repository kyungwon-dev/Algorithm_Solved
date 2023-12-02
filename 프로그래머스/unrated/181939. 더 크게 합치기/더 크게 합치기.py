def solution(a, b):
    a_b = int(str(a) + str(b))
    b_a = int(str(b) + str(a))
    if a_b > b_a:
        return a_b
    return b_a