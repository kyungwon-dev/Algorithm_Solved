import heapq

def solution(operations):
    minmax_heap = []
    for operation in operations:
        operation = operation.split()

        if operation[0] == "I":
            heapq.heappush(minmax_heap, int(operation[1]))
        else:
            if not minmax_heap:
                continue
            if int(operation[1]) == -1:
                heapq.heappop(minmax_heap)
            else:
                minmax_heap.sort()
                minmax_heap.pop()
        # print(minmax_heap)
    minmax_heap.sort()
    if not minmax_heap:
        return [0,0]
    return [minmax_heap[-1], minmax_heap[0]]