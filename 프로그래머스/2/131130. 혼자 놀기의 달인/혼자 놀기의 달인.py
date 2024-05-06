
from collections import Counter
def solution(cards):
    answer = 0
    root = [-1 for _ in cards]
    cards = [c-1 for c in cards]
    # print(root)
    # print(cards)
    group_index = 0
    for i in range(len(cards)):
        if root[i] != -1:
            continue
        root[i] = group_index
        tmp = cards[i]
        while root[tmp] == -1:
            root[tmp] = group_index
            tmp = cards[tmp]
            
        group_index+=1
    
    
    root = sorted(list(Counter(root).values()), reverse=True)
    if len(root) > 1:
        answer = root[0] * root[1]

    return answer