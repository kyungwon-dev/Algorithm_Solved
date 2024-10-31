import sys
sys.setrecursionlimit(10**8)
user_select = []
banned_case = []

def recur(selected, end, user_id, banned_id ):
    if selected >= end:
        tmp = []
        for i in range(len(user_select)):
            if user_select[i]:
                tmp.append(user_id[i])
        banned_case.append(tmp)
        return
    for i in range(len(user_id)):
        if len(banned_id[selected]) != len(user_id[i]):
            continue
        isCorrect = True
        if user_select[i]:
            continue
        for j in range(len(user_id[i])):
            if banned_id[selected][j] == "*":
                continue
            if banned_id[selected][j] == user_id[i][j]:
                continue
            else:
                isCorrect = False
        
        if not isCorrect:
            continue

        user_select[i] = True
        recur(selected+1, end, user_id, banned_id)
        user_select[i] = False

def solution(user_id, banned_id):
    global user_select 
    global banned_case
    user_select = [False for _ in range(len(user_id))]
    answer = 0
    # print(user_select)
    # print(banned_id)
    # print(user_id)
    
    recur(0, len(banned_id), user_id, banned_id)
    
    
    answer = len(set(list(map(tuple,banned_case))))
    return answer