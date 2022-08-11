import sys
chess = [1,1,2,2,2,8]
inputs = list(map(int, sys.stdin.readline().strip().split()))
inputs = [str(chess[i] - inputs[i]) for i in range(6)]
print(f"{' '.join(inputs)}")

    