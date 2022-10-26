boards = [ list(map(int, input().split())) for _ in range(9)]
max_i = 0
max_j = 0
max_value = -1
for i in range(len(boards)):
    for j in range(len(boards[i])):
        if max_value <= boards[i][j]:
            max_i = i
            max_j = j
            max_value = boards[i][j]
            
print(max_value)
print(max_i+1,max_j+1,sep=" ")