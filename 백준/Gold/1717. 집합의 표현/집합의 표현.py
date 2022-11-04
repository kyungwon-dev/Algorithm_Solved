import sys
import collections, bisect, heapq, itertools
# setting
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
max_inf = sys.maxsize

N, M = map(int, input().strip().split())
parent = [i for i in range(N+1)]

def find(elem : int) -> int:
    if parent[elem] != elem:
        parent[elem] = find(parent[elem])
    return parent[elem]

def union(e1, e2):
    p1 = find(e1)
    p2 = find(e2)
    
    if p1 > p2:
        parent[p1] = parent[p2]
    else:
        parent[p2] = parent[p1]

for l in range(M):
    cmd, elem1, elem2 = map(int, input().strip().split())
    
    if cmd == 0: # union
        union(elem1, elem2)
    else: # find
        if find(elem1) == find(elem2):
            print("YES")
        else:
            print("NO")