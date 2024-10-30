def solution(mats, park):
    answer = -1
    # 50 * 50 * (20 * 10) * (50*50) : 625 * 10000 * 200 < 1억
    y_max, x_max = len(park), len(park[0])
    
    mats = [m for m in mats if m <= min(y_max, x_max)]
    mats.sort(reverse=True)
    # print(mats)
    
    if not mats:
        return -1
    
    for i in range(len(park)):
        for j in range(len(park[i])):
            
            if park[i][j] == "-1":
                for m in mats:
                    isRect = True
                    for k in range(i, i+m):
                        if k >= len(park):
                            isRect = False
                            break
                        for l in range(j, j+m):
                            if l >= len(park[0]):
                                isRect = False
                            
                            elif park[k][l] != "-1":
                                isRect = False
                            
                            if not isRect:
                                break
                        if not isRect:
                            break
                    if isRect:
                        # print(m)
                        answer = max(answer, m)
    
    return answer