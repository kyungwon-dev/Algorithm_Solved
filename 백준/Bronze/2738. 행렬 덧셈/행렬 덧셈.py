N, M = [int(x) for x in input().split()]
matrix = []
for i in range(N):
    rows = [int(x) for x in input().split()]
    matrix.append(rows) 
for i in range(N):
    rows = [int(x) for x in input().split()]
    for idx, val in enumerate(rows):
        matrix[i][idx] += val
for m in matrix:
    print(f"{' '.join([str(x) for x in m])}")