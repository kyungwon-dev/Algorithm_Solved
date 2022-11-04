import sys
import collections, bisect, heapq, itertools
# setting
sys.setrecursionlimit(10**5)
input = sys.stdin.readline
max_inf = sys.maxsize

V, E = map(int , input().strip().split())
parent = [i for i in range(V+1)]
graph = []
# kruskal

def find(element):
    if parent[element] != element:
        parent[element] = find(parent[element])
    return parent[element]

def merge(element1, element2):
    element1 = find(element1)
    element2 = find(element2)
    
    if element1 == element2:
        return False
    min_parent = min(element1, element2)
    parent[element1] =  min_parent
    parent[element2] =  min_parent
    return True
    
for i in range(E):
    s_node, d_node, prior = map(int , input().strip().split())
    graph.append( (prior, s_node, d_node))
heapq.heapify(graph)
answer = 0
while graph:
    prior, s_node, d_node = heapq.heappop(graph)
    if merge(s_node, d_node):
        answer += prior
print(answer)