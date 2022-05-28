import itertools

def solution(k, dungeons):
    answer = 0
    print(len(dungeons))
    cases = [i for i in range(len(dungeons))]
    cases = list(itertools.permutations(cases,len(dungeons)))
    for case in cases:
        p = k;
        sub_answer = 0
        for idx in case:
            if p >= dungeons[idx][0]:
                p -=dungeons[idx][1]
                sub_answer +=1
            else:
                continue
        answer = max(answer,sub_answer)
    return answer