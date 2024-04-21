from collections import deque
def solution(board):
    answer = 0
    # -1 : 방문안함 또는 못함 , >=0 : 방문할 수 있는 수행횟수
    visited_board = [ [-1 for _ in range(len(board[0]))] for _ in range(len(board))]
    goal = []
    
    dy , dx  = [0,1,0,-1], [1,0,-1,0] # 우하좌상
    for i in range(len(board)):
        for j in range(len(board[0])):
            if board[i][j] == "G":
                goal = [i,j]
            if board[i][j] == "R":
                visited_board[i][j] = 0
                bfs = deque([])
                bfs.append([i,j])
                while bfs:
                    y, x = bfs.popleft()
                    for d in range(4):
                        sy, sx = y , x
                        diff = 1
                        while True:
                            sy = y + ( dy[d] * diff)
                            sx = x + ( dx[d] * diff)
                            if (0<=sy<len(board)) and (0<=sx<len(board[0])) and board[sy][sx] != "D":
                                diff+=1
                            else:
                                break
                        diff -=1
                        
                        if diff != 0:
                            sy = y + ( dy[d] * diff)
                            sx = x + ( dx[d] * diff)
                            if visited_board[sy][sx] == -1:
                                bfs.append([sy, sx])
                                visited_board[sy][sx] = visited_board[y][x] + 1
                            # print("!", d)
                            
    # print(visited_board)
    return visited_board[goal[0]][goal[1]]