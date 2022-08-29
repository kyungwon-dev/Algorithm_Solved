import heapq
from collections import deque

def solution(jobs):
    answer = process_time = 0
    len_jobs = len(jobs)
    jobs.sort(key= lambda x: x[0])
    no_wait = 0
    while jobs:
        serve_first= []
        for idx, [start, duration] in enumerate(jobs):    
            if start > process_time:
                break
            heapq.heappush(serve_first, (duration, [idx, start, duration]))

        if serve_first:
            nx = heapq.heappop(serve_first)
            answer = answer + nx[1][2] + (process_time - nx[1][1])
            process_time = process_time + nx[1][2]

            jobs.pop(nx[1][0])
        else:
            process_time = jobs[0][0]
            no_wait += jobs[0][0] - process_time
        
    return int( (answer) / len_jobs)