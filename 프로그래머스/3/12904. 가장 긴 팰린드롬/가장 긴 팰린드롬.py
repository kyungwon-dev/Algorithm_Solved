def solution(s):
    answer = 1

    # [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.

    for i in range(0, len(s)-1):
        # 홀수 체크
        max_len = min(i - 0 , len(s) - i - 1 )

        # print(i, max_len)  
        tmp_answer = 1
        l,r = i,i
        while 0< l and r<len(s)-1:
            l-=1
            r+=1
            if s[l] == s[r]:
                tmp_answer+=2
            else:
                break
        if tmp_answer > answer:
            # print("!", s[l], s[r], tmp_answer)
            answer = tmp_answer
        tmp_answer = 2
        l,r = i,i+1
        if s[l] != s[r]:
            continue
        while 0< l and r<len(s)-1:
            l-=1
            r+=1
            if s[l] == s[r]:
                # print("!!", s[l], s[r])
                tmp_answer+=2
            else:
                break
        if tmp_answer > answer:
            answer = tmp_answer
    
    
    return answer