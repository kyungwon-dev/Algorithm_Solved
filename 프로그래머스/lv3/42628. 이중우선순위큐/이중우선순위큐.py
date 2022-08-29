import heapq

def solution(operations):
    min_heap = []
    max_heap = []
    cnt = 0
    for operation in operations:
        operation = operation.split()
        operation[1] = int(operation[1])
        
        if operation[0] == "I":
            heapq.heappush(min_heap, operation[1] )
            heapq.heappush(max_heap, -operation[1] )
            cnt += 1
        else:
            if cnt == 0:
                continue
            if operation[1] == -1:
                heapq.heappop(min_heap)
            else:
                heapq.heappop(max_heap)
            cnt -=1
            if cnt == 0:
                min_heap.clear()
                max_heap.clear()
    # print(min_heap)
    # print(max_heap)
    if cnt == 0:
        return [0,0]
    return [-heapq.heappop(max_heap), heapq.heappop(min_heap)]