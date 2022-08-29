import heapq

def solution(operations):
    num_dict = {}
    min_heap = []
    max_heap = []
    cnt = 0
    for operation in operations:
        operation = operation.split()
        operation[1] = int(operation[1])
        
        if operation[0] == "I":
            heapq.heappush(min_heap, operation[1] )
            heapq.heappush(max_heap, -operation[1] )
            if operation[1] not in num_dict:
                num_dict[operation[1]] = 1
            else:
                num_dict[operation[1]] += 1
            cnt += 1
        else:
            if cnt == 0:
                continue
            if operation[1] == -1:
                num = heapq.heappop(min_heap)
                while num_dict[num] == 0:
                    num = heapq.heappop(min_heap)
                num_dict[num] -= 1    
                
            else:
                num = -heapq.heappop(max_heap)
                while num_dict[num] == 0:
                    num = -heapq.heappop(max_heap)
                num_dict[num] -= 1    
            cnt -=1
            if cnt == 0:
                min_heap = []
                max_heap = []
    if cnt == 0:
        return [0,0]
    
    mx = 0
    mn = 0
    for i in range(len(max_heap)):
        mx = -heapq.heappop(max_heap)
        if num_dict[mx] == 0:
            continue
        else:
            break
    for i in range(len(min_heap)):
        mn = heapq.heappop(min_heap)
        if num_dict[mn] == 0:
            continue
        else:
            break
    return [mx,mn]