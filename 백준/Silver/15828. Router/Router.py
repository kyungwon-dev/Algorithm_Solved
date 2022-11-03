import sys
from collections import deque
sys.setrecursionlimit(10**5)

# input
N = int(sys.stdin.readline().strip())
router_buffer = deque([])
while True:
    packet = sys.stdin.readline().strip()
    if packet == "-1":
        break
    if len(router_buffer) <= N:
        if packet == "0":
            router_buffer.popleft()
        else:
            if len(router_buffer) == N:
                continue
            router_buffer.append(packet)
if not router_buffer:
    print("empty")
else:
    print(" ".join(router_buffer))
