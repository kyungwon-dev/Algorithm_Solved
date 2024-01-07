def solution(ineq, eq, n, m):
    answer = 0
    op = ineq + eq
    if op == ">=":
        if n >= m:
            return 1
    elif op == "<=":
        if n <= m:
            return 1
    elif op == ">!":
        if n > m:
            return 1
    elif op == "<!":
        if n < m:
            return 1
    return 0