def time_to_int(hhmm):
    hh, mm = list(map(int, hhmm.split(":")))
    return hh * 60 + mm
    
def int_to_time(x):
    return ( "0"+str(x//60) if len(str(x//60)) < 2 else str(x//60) )  + ":" + ( "0"+str(x%60) if len(str(x%60)) < 2 else str(x%60) )
def solution(n, t, m, timetable):
    answer = 0
    timetable = list(map(lambda x : time_to_int(x), timetable))
    timetable.sort()
    
    start = time_to_int("09:00")
    board_dict = {
        i : [] for i in list(map(int, [start + ( t ) * (i) for i in range(n)]))
    }
    
    print(board_dict)
    print(timetable)
    
    keys = list(board_dict.keys())
    idx = -1
    for k in keys:
        
        for t in range(idx+1, len(timetable)):
            if timetable[t] <= k and len(board_dict[k]) < m:
                board_dict[k].append(timetable[t])
                idx+=1

    print(board_dict)
    
    keys.reverse()
    idx = 0
    for k in keys:
        print(k)
        if len(board_dict[k]) == 0:
            answer = k
            break
        elif len(board_dict[k]) < m:
            pos = max(board_dict[k]) + 1
            if pos <= k:
                pos = k
            answer = pos
            break
        elif len(board_dict[k]) == m:
            pos = min(board_dict[k])
            if pos == max(board_dict[k]):
                pos-=1
            answer = pos
            break
    
    
    return int_to_time(int(answer))