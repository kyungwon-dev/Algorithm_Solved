import sys
prev_stack = list(sys.stdin.readline().strip())
next_stack = list()
n = int(sys.stdin.readline().strip())
for i in range(n):
    cmd = list(sys.stdin.readline().strip().split())
    if cmd[0] == 'P':
        prev_stack.append(cmd[1])
    elif cmd[0] == "L":
        if len(prev_stack) == 0:
            continue
        next_stack.append(prev_stack.pop())
    elif cmd[0] == "D":
        if len(next_stack) == 0:
            continue
        prev_stack.append(next_stack.pop())
    else:
        if len(prev_stack) == 0:
            continue
        prev_stack.pop()
next_stack.reverse()
answer = "".join(prev_stack) + "".join(next_stack)

print(answer)