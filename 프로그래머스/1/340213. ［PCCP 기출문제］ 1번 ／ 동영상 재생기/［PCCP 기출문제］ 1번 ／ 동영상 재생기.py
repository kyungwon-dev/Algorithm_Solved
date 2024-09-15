def time_to_int(t):
    h, s = list(map(int, t.split(":")))
    return h * 60 + s

def int_to_time(i):
    h, s = i//60, i%60
    
    return (str(h) if h>=10 else "0"+str(h)) + ":" + (str(s) if s>= 10 else "0"+str(s))

def solution(video_len, pos, op_start, op_end, commands):
    answer = ''
    video_len = time_to_int(video_len)
    pos = time_to_int(pos)
    op_start = time_to_int(op_start)
    op_end = time_to_int(op_end)
    if op_start <= pos <= op_end:
        pos = op_end    
        
    for command in commands:
        if op_start <= pos <= op_end:
            pos = op_end
        
        if command == "next":
            pos+=10
        else:
            pos-=10
        
        if pos >= video_len:
            pos = video_len
            
        if op_start <= pos <= op_end:
            pos = op_end
        
        if pos <= 0:
            pos = 0
    
    return int_to_time(pos)