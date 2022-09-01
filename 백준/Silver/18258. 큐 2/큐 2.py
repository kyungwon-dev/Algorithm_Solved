from collections import deque
import sys
N = int(sys.stdin.readline().strip())
dq = deque([])
for i in range(N):
    command = sys.stdin.readline().strip().split()
    if len(command) == 2:
        command, X = command[0], command[1]
    else:
        command = command[0]
    if command == "push":
        dq.append(X)
    elif command == "pop":
        if not dq:
            print("-1")
        else:
            print(dq.popleft())
    elif command == "size":
        print(len(dq))
    elif command == "empty":
        if dq:
            print("0")
        else:
            print("1")
    elif command == "front":
        if dq:
            print(dq[0])
        else:
            print("-1")
    else:
        if dq:
            print(dq[-1])
        else:
            print("-1")
    
        
    