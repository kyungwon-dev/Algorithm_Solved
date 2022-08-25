import sys
N = int(sys.stdin.readline().strip())
stack = []
out = []
top = 0
is_correct = True
for i in range(N):
    num = int(sys.stdin.readline().strip())
    while top < num:
        top +=1
        stack.append(top)
        out.append('+')
    
    if stack[-1] == num:
        out.append('-')
        stack.pop()
    else:
        print("NO")
        is_correct = False
        break
if is_correct:
    for o in out:
        print(o)