def solution(players, m, k):
    answer = 0
    increased = [0 for _ in range(len(players))]
    for i in range(len(players)):
        if players[i] // ( (increased[i] + 1) * m ) > 0:
            inc = (players[i] - ( (increased[i]) * m )) // m 

            if players[i] == 13:
                print(increased[i], inc, (increased[i] + 1) * m)
            for j in range(i, min(i+k, len(increased))):
                increased[j]+=inc
            answer+=inc
    print(increased)
    return answer