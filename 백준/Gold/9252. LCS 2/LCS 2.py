import sys
str1 = sys.stdin.readline().strip()
str2 = sys.stdin.readline().strip()

d =[ [0 for _ in range(len(str1) + 1)] for _ in range(len(str2)+1) ]
for i in range(1, len(str2)+1):
    for j in range(1, len(str1) + 1):
        if str1[j-1] == str2[i-1]:
            d[i][j] = d[i-1][j-1] + 1
            
        else:
            d[i][j] = max(d[i-1][j], d[i][j-1])
print(d[-1][-1])

answer = []
y, x = len(d)-1, len(d[0]) -1
while d[y][x] != 0:
    if d[y][x] == d[y-1][x]:
        y = y-1
    elif d[y][x] == d[y][x-1]:
        x = x-1
    else:
        answer.append(str1[x-1])
        y = y-1
        x = x-1
print("".join(reversed(answer)))