def solution(X, Y):
    answer = ''
    x_nums = [0 for _ in range(10)]
    y_nums = [0 for _ in range(10)]
    for c in X:
        x_nums[ord(c) - ord('0')]+=1
    for c in Y:
        y_nums[ord(c) - ord('0')]+=1
        
    for n in range(10 -1, 0 -1, -1):
        answer += (str(n) * min(x_nums[n], y_nums[n]))
    if answer == '':
        answer = "-1"
    if answer[0] == '0':
        answer = '0'
    return answer