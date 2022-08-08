import sys

n = int(sys.stdin.readline().rstrip())
stack = []
for i in range(n):
    s = sys.stdin.readline().rstrip().split()
    cmd = s[0]
    if cmd == "push":
        stack.append(s[1])    
    elif cmd == "pop":
        if len(stack) > 0:
            print(f"{stack.pop(0)}")
        else:
            print("-1")
    elif cmd == "size":
        print(len(stack))
    elif cmd == "empty":
        if len(stack) > 0:
            print("0")
        else:
            print("1")        
    elif cmd == "front":
        if len(stack) > 0:
            print(f"{stack[0]}")
        else:
            print("-1")
    else:
        if len(stack) > 0:
            print(f"{stack[-1]}")
        else:
            print("-1")