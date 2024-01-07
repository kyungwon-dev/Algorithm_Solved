from collections import deque

def solution(arr):
    stk = deque([])
    i = 0
    while i < len(arr):
        if len(stk) == 0:
            stk.append(arr[i])
            i+=1
        else:
            if stk[-1] < arr[i]:
                stk.append(arr[i])
                i+=1
            else:
                stk.pop()
    return list(stk)