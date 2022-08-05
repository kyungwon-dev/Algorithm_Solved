from collections import deque
import sys
N = int(sys.stdin.readline().rstrip())
cards = deque(list(range(1, N+1)))
while len(cards) > 1:
    cards.popleft()
    cards.append(cards.popleft())

print(cards[0])