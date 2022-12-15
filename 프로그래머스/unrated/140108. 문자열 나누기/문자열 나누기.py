def solution(s):
    answer = 0
    while len(s)>=2:
        x = s[0]
        x_cnt , not_x_cnt = 0, 0
        is_split = False
        for i in range(len(s)):
            if x == s[i]:
                x_cnt+=1
            else:
                not_x_cnt +=1
            if x_cnt == not_x_cnt:
                answer+=1
                s = s[i+1:]
                is_split = True
                break
        # print(s)
        if is_split == False:
            break
    if(len(s) !=0):
        answer+=1
    return answer