def solution(date1, date2):
    for d1, d2 in zip(date1, date2):
        if d1 < d2:
            return 1
        elif d1==d2:
            continue
        else:
            return 0
    return 0