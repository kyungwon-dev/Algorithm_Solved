def solution(friends, gifts):
    answer = 0
    num_to_friend  = { i:friends[i] for i in range(len(friends)) }
    friend_to_num = { str(friends[i]):i for i in range(len(friends)) }
    friend_gift_index = { str(friends[i]):0 for i in range(len(friends)) }
    
    gifts_map = [[0 for j in range(len(friends))] for i in range(len(friends))]
    for gift in gifts:
        snd, rcv = list(map(str, gift.split(" ")))
        gifts_map[friend_to_num[snd]][friend_to_num[rcv]] += 1
        
    for i, f in num_to_friend.items():
        friend_gift_index[f] = sum(gifts_map[i][:]) - sum([gifts_map[j][i] for j in range(len(gifts_map))])

    gift_result = [0 for _ in range(len(friends))]
    for i in range(len(gifts_map)):
        for j in range(len(gifts_map)):

            if i==j:
                continue
            if gifts_map[i][j] > gifts_map[j][i] :
                gift_result[i]+=1
            elif gifts_map[i][j] == gifts_map[j][i]:
                if friend_gift_index[num_to_friend[j]] < friend_gift_index[num_to_friend[i]]:
                    gift_result[i]+=1
    return max(gift_result)