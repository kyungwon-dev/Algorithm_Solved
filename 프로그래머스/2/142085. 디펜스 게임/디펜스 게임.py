import heapq
def solution(n, k, enemy):
    answer = 0
    stage = []
    # 우선순위 큐 사용.
    # enemy의 최대 길이는 1000000
    # 따라서 시간복잡도 고려. n^2로는 해결 불가능. nlogn 으로 해결 가능
    
    if k >= len(enemy):
        return len(enemy)
    
    for i in range(0, len(enemy)):
        heapq.heappush(stage, enemy[i])
        if len(stage) > k: # 통과한 길이가 무적권 개수보다 더 클 때
            minimum = heapq.heappop(stage) # 가장 약한 적은 무적권을 사용 안함
            n -= minimum # 사용하지 않으므로 제거
            if n < 0: # 가장 약한 적을 무적권 사용하지 않고도 제거 불가능하다면, 최대 stage에 도달했다고 볼 수 있다.
                return answer 
                
        answer+=1
    return answer