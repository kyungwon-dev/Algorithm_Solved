def solution(sticker):
    answer = 0
    
    # 3개만 있는 경우 가장 큰 것만 떼면 됨
    if len(sticker) <= 3:
        return max(sticker)

    # [14, 6, 5, 11, 3, 9, 2, 10]
    # [14, 14(i-1), 19(i + i-2), 11+14(i + i-2), ...]

    # 원형DP의 경우, 해당 방식으로 처리하기 - 첫번째선택/두번째선택
    # 첫번째 스티커를 떼는 케이스
    dp_f = [0] + sticker[:-1] # 마지막은 제외
    for i in range(2, len(sticker)):
        dp_f[i] = max(dp_f[i-1], dp_f[i] + dp_f[i-2])
    
    # 두번째 스티커를 떼는 케이스
    dp_s = [0] + sticker[1:] # 마지막은 제외
    for i in range(2, len(sticker)):
        dp_s[i] = max(dp_s[i-1], dp_s[i] + dp_s[i-2])
    
    answer = max(dp_f[-1], dp_s[-1])

    return answer