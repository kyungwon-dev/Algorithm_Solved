from collections import Counter

def solution(k, tangerine):
    answer = 0
    total = len(tangerine)
    box = sorted(dict(Counter(tangerine)).items(), key=lambda x : x[1] )
    for i in range(len(box)):
        if total - box[i][1] >= k:
            total -= box[i][1]
        else:
            return len(box) - i
    return 0