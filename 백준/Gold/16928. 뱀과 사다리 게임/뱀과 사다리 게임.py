import sys
import collections, bisect, heapq
# setting
sys.setrecursionlimit(10**5)
input = sys.stdin.readline
N, M = map(int, input().strip().split())
not_visited = 10000
board = [not_visited for _ in range(100+1)]
snake_radder = {}
for i in range(N+M):
    prev, next = map(int, input().strip().split())
    snake_radder[prev] = next

q = collections.deque([1])
lvl = 1
board[1] = 0
while q:
    length = len(q)
    for l in range(length):
        current = q.popleft()
        for dist in range(1, 7):
            next = current + dist
            if next > 100 or board[next] < not_visited:
                continue
            board[next] = lvl
            q.append(next)
            if snake_radder.get(next) != None:
                q.pop()
                if board[snake_radder[next]] < not_visited:
                    continue
                board[snake_radder[next]] = lvl
                q.append(snake_radder[next])
    lvl+=1
    if board[100] < not_visited:
        break
print(board[100])