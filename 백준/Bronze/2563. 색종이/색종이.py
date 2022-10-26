boards = [ [0 for _ in range(100)] for _ in range(100)]
N = int(input())
for n in range(N):
    col, row = map(int, input().split())
    for i in range(row -1, row+10 -1):
        for j in range(col -1, col+10 -1):
            boards[i][j] = 1
answer = 0
for i in range(100):
    for j in range(100):
        answer += boards[i][j]
print(answer)