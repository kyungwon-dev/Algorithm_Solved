def solution(name, yearning, photo):
    answer = []
    score = {
        k:v for k,v in zip(name,yearning)
    }
    for p in photo:
        num = 0
        for pp in p:
            if pp in name:
                num = num + score[pp]
        answer.append(num)
    return answer