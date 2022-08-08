import sys

n = int(sys.stdin.readline().rstrip())
for i in range(n):
    paren_str = sys.stdin.readline().rstrip()
    stack = []
    VPS = True
    for pstr in paren_str:
        if pstr == "(":
            stack.append(pstr)
        else:
            if len(stack) == 0:
                VPS = False
                break
            else:
                stack.pop()
    if len(stack) != 0:
        VPS = False
    if VPS:
        print("YES")
    else:
        print("NO")
        