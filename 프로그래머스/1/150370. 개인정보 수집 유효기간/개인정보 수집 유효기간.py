def calc_date(prev_day)->int:
    y, m , d = list(map(int, prev_day.split(".")))
    y = (y - 2000) * 12 * 28 # day 
    m = (m-1) * 28
    return y + m + d

def solution(today, terms, privacies):
    answer = []
    term_dict = { t[0]:int(t[2:]) for t in terms }
    today = calc_date(today)
    i = 1
    # print(today)
    # print(term_dict)
    for privacy in privacies:
        privacy_day, privacy_type = privacy.split(" ")
        privacy_day = calc_date(privacy_day) + (term_dict[privacy_type] * 28) - 1
        if privacy_day < today:
            answer.append(i)
        # print(privacy_day)
        i+=1
    
    return answer