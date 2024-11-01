def solution(gems):
    answer = []
    l,r = 0,0
    all_gems_cnt = len(set(gems))
    if all_gems_cnt == len(gems):
        return [1, len(gems)]
    gems_dict = {}

    while not (l > len(gems) or r > len(gems)) :

        if len(gems_dict) == all_gems_cnt:
            
            gems_dict[gems[l]] -=1

            if gems_dict[gems[l]] == 0:
                del gems_dict[gems[l]]
                answer.append([l+1, r])
                if r == 1:
                    return answer[0]

            l+=1
            
        else:
            if r == len(gems) or l == len(gems):
                break
        
            gems_dict[gems[r]] = gems_dict.get(gems[r], 0) + 1
            r+=1
        
    answer.sort(key=lambda x : (x[1]-x[0], x[0]) )
    
    return answer[0]