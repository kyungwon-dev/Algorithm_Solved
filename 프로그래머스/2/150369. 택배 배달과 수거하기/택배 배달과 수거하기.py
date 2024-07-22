def solution(cap, n, deliveries, pickups):
    answer = 0
    deliveries, pickups = [0] + deliveries, [0] + pickups
    # two-point 접근
    deliveries_idx, pickups_idx = n, n
    
    while deliveries_idx != 0 and pickups_idx != 0:
        d_len = 0
        d_carry = cap
        while d_carry != 0 and deliveries_idx != 0:
            if deliveries[deliveries_idx] != 0:
                if d_len == 0:
                    d_len = deliveries_idx
                diff = min(d_carry, deliveries[deliveries_idx])
                d_carry = d_carry - diff
                deliveries[deliveries_idx] -= diff 
            if deliveries[deliveries_idx] == 0:
                deliveries_idx -=1
        
        p_len = 0
        p_carry = cap
        while p_carry != 0 and pickups_idx != 0:
            if pickups[pickups_idx] != 0:
                if p_len == 0:
                    p_len = pickups_idx
                diff = min(p_carry, pickups[pickups_idx])
                p_carry = p_carry - diff
                pickups[pickups_idx] -= diff 
            if pickups[pickups_idx] == 0:    
                pickups_idx -=1
        
        answer += max(p_len, d_len)
        # print(deliveries_idx, pickups_idx)
        # print(deliveries, pickups)
        # print(answer)
        
    while deliveries_idx != 0:
        d_len = 0
        d_carry = cap
        while d_carry != 0 and deliveries_idx != 0:
            if deliveries[deliveries_idx] != 0:
                if d_len == 0:
                    d_len = deliveries_idx
                diff = min(d_carry, deliveries[deliveries_idx])
                d_carry = d_carry - diff
                deliveries[deliveries_idx] -= diff 
            if deliveries[deliveries_idx] == 0:
                deliveries_idx -=1
        answer += d_len
    
    while pickups_idx != 0:
        p_len = 0
        p_carry = cap
        while p_carry != 0 and pickups_idx != 0:
            if pickups[pickups_idx] != 0:
                if p_len == 0:
                    p_len = pickups_idx
                diff = min(p_carry, pickups[pickups_idx])
                p_carry = p_carry - diff
                pickups[pickups_idx] -= diff 
            if pickups[pickups_idx] == 0:    
                pickups_idx -=1
        answer += p_len
        # print(pickups_idx)
        # print(pickups)
        # print(answer)

        
    
    return answer * 2