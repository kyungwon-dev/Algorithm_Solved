from dis import dis
import sys
n, c, r = map(int, sys.stdin.readline().strip().split())
min_value = 1
max_value = ( 2 ** (2*n) ) 
while min_value != max_value:
    quadrant_base = 2** (n-1)
    dist = 2 ** (2*n - 2)
    if r <  quadrant_base and c < quadrant_base:
        # 1z
        min_value = min_value
        pass
    elif r >= quadrant_base and c < quadrant_base:
        # 2z
        min_value = min_value + dist 
        pass
    elif r < quadrant_base and c >= quadrant_base:
        # 3z
        min_value = min_value + 2*dist 
        pass
    else:
        # 4z
        min_value = min_value + 3*dist 
        pass
    max_value = min_value + dist - 1
    # print(min_value, max_value)
    r = r - quadrant_base if r >= quadrant_base else r
    c = c - quadrant_base if c >= quadrant_base else c   
    n = n-1
print(min_value-1)
      
