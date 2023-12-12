def solution(a, b, c):
    answer = a+b+c
    if a==b or b==c or c==a:
        if a==b and b==c and c == a:
            answer = answer * (a**2 + b**2 + c**2) * (a**3 + b**3 + c**3)
        else:
            answer = answer * (a**2 + b**2 + c**2)

    return answer