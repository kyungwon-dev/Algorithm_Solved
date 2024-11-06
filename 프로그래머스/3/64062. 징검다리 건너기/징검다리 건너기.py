def solution(stones, k):
    answer = 0
    
    l, r = 1, max(stones) # 최대 지나갈 수 있는 인원은 stones 배열 중 가장 큰 값. 최소값은 최소 stones 값인 1
    
    # 전체 케이스를 탐색하려면, 200,000 * 200,000 = 40,000,000,000 -> 시간초과.
    # 이진 탐색을 수행하면, log(200,000) * 200,000 = 200,000 * log(2^10 * 2^7) = 3,400,000
    j = 0
    while l < r:
        mid = (l+r) // 2
        no_step = 0 # 연속으로 돌을 밟을 수 없는 개수
        for stone in stones:
            if mid >= stone :
                no_step +=1
            else:
                no_step =0 # 초기화
            
            if no_step >= k: # k개 이상인 경우 측정 불가.
                r = mid
                break
        if no_step < k:
            l = mid+1

        j +=1


    return (l+r) // 2