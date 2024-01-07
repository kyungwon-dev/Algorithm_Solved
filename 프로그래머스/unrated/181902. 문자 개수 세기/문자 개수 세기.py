def solution(my_string):
    answer = [0 for _ in range(52)]
    for s in my_string:
        if(ord('a') <= ord(s) <= ord('z')):
            answer[ord(s) - ord('a') + 26]+=1
        else:
            answer[ord(s) - ord('A')]+=1
    return answer