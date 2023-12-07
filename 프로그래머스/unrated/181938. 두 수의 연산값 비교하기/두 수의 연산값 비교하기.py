def solution(a, b):
    answer = 0
    a_b = int(str(a) + str(b))
    mul_a_b = 2 * a * b
    return a_b if a_b > mul_a_b else mul_a_b