def solution(bandage, health, attacks):
    answer = health
    attack_index = 0
    continuity_success = 0
    for i in range(1, attacks[-1][0]+1):
        if attacks[attack_index][0] == i:
            continuity_success = 0
            answer -= attacks[attack_index][1]
            attack_index+=1
            if answer <= 0:
                return -1
        else:
            answer += bandage[1]
            continuity_success +=1
            if continuity_success == bandage[0]:
                answer += bandage[2]
                continuity_success = 0
            if answer > health:
                answer = health
        # print(i, answer)
                
    return answer