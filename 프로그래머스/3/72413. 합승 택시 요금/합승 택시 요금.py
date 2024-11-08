def solution(n, s, a, b, fares):
    answer = 10**8
    taxi_map = [[10**20 if i!=j else 0 for j in range(n)] for i in range(n)]
    
    s, a, b= s-1, a-1, b-1 # 좌표 변환
    for fare in fares:
        taxi_map[fare[0]-1][fare[1]-1] = min(fare[2], taxi_map[fare[0]-1][fare[1]-1])
        taxi_map[fare[1]-1][fare[0]-1] = min(fare[2], taxi_map[fare[1]-1][fare[0]-1])
    

    # 플루이드-워셜 200 * 200 * 200 < 1억
    for k in range(n):
        for j in range(n):
            for i in range(n):
                if i==j:
                    continue
                taxi_map[i][j] = min(taxi_map[i][j], taxi_map[i][k] + taxi_map[k][j])

    for i in range(len(taxi_map)):
        # print(taxi_map[i])
        answer = min(taxi_map[s][i] + taxi_map[i][a] + taxi_map[i][b], min(answer, taxi_map[s][a] + taxi_map[s][b]))
    
    return answer