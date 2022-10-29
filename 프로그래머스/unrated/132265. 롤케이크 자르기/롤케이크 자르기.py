from collections import Counter

def solution(topping):
    answer = 0
    rp_counter = dict(Counter(topping))
    lp_counter = {k:0 for k in rp_counter.keys()}
    rp_flavor , lp_flavor = len(rp_counter.keys()), 0
    
    for i in range(len(topping)):
        k = topping[i]
        lp_counter[k]+=1
        if lp_counter[k] == 1:
            lp_flavor+=1
        rp_counter[k]-=1
        if rp_counter[k] == 0:
            rp_flavor-=1
        if lp_flavor == rp_flavor:
            answer+=1
    return answer