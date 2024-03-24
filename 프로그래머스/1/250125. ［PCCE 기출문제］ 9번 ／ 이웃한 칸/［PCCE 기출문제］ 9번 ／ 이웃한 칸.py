def solution(board, h, w):
    answer = 0
    dh, dw = [0, 1, -1, 0], [1, 0, 0, -1]
    for d in range(4):
        sh = h + dh[d]
        sw = w + dw[d]
        if sh < 0 or sh >= len(board) or sw < 0 or sw >= len(board[0]):
            continue
        if board[h][w] == board[sh][sw]:
            answer+=1
    return answer