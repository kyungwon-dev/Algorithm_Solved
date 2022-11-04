import sys
from collections import deque
from bisect import bisect_left
sys.setrecursionlimit(10**5)

mr = [-1,-2,-2,-1,1,2,2,1]
mc = [-2,-1,1,2,-2,-1,1,2]

# input
T = int(sys.stdin.readline().strip()) # testcases
for testcase in range(T):
    l = int(sys.stdin.readline().strip())
    board = [[ 0 for _ in range(l)] for _ in range(l)]
    sr, sc = list(map(int, sys.stdin.readline().strip().split()))
    dr, dc = list(map(int, sys.stdin.readline().strip().split()))
    q = deque([])
    q.append((sr,sc))
    board[sr][sc] = 1
    while q:
        r, c = q.popleft()
        for move in range(8):
            tr = r + mr[move]
            tc = c + mc[move]
            if (0<= tr < l and 0 <= tc < l) and board[tr][tc] == 0:
                q.append((tr,tc))
                board[tr][tc] = board[r][c] + 1
    print(board[dr][dc]-1)