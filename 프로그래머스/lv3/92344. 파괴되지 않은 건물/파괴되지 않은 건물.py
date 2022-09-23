def solution(board, skills):
    answer = len(board) * len(board[0])
    acc_sum_board = [[0 for _ in range(len(board[0])+1)] for _ in range(len(board)+1)]

    for skill in skills:
        if skill[0] == 1:
            skill[5] = -skill[5]
        acc_sum_board[skill[1]][skill[2]] += skill[5]
        
        acc_sum_board[skill[1]][skill[4]+1] += -skill[5]
        acc_sum_board[skill[3]  + 1][skill[2]] += -skill[5]
        
        acc_sum_board[skill[3]  + 1][skill[4]+1] += skill[5]

    # up -> down
    for i in range(1, len(acc_sum_board)):
        for j in range(len(acc_sum_board[0])):
            acc_sum_board[i][j] += acc_sum_board[i-1][j]

    # left -> right
    for i in range(len(acc_sum_board)):
        for j in range(1, len(acc_sum_board[0])):
            acc_sum_board[i][j] += acc_sum_board[i][j-1]
    
    for i in range(len(board)):
        for j in range(len(board[0])):
            board[i][j] += acc_sum_board[i][j]
            if board[i][j] <= 0:
                answer -=1
    
    
    
    return answer