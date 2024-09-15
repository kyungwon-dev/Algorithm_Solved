def solution(N, road, K):
    max_distance = 500000 * 20 + 1
    
    ## 초기화
    road_map = [[max_distance if i!=j else 0 for j in range(N)] for i in range(N)]
    
    ## 그래프 길이 저장
    for r in road:
        s, d, l = r
        road_map[s-1][d-1] = min(l, road_map[s-1][d-1])
        road_map[d-1][s-1] = min(l, road_map[d-1][s-1])
    
    # print(road_map)
    
    ## Floyed Washal
    ## i -> 거쳐가는 노드 / j -> 출발 노드 / k -> 도착 노드
    for i in range(N):
        for j in range(N):
            for k in range(N):
                if road_map[j][k] > road_map[j][i] + road_map[i][k]:
                    road_map[j][k] = min(road_map[j][k] , road_map[j][i] + road_map[i][k])
    
    # print(road_map)
    # print(road_map[0])
    return sum([r <= K for r in road_map[0]])