def solution(book_time):
    answer = 0
    time_table =  [ 0 for _ in range(60*24)] # 분단위로 24시간
    for btime in book_time:
        
        start_hour, start_minute = btime[0].split(':')
        start_hour = int(start_hour) * 60 + int(start_minute)
        
        end_hour, end_minute = btime[1].split(':')
        end_hour = int(end_hour) * 60 + int(end_minute)
        
        for i in range(start_hour, min(end_hour+10, 24*60)):
            time_table[i]+=1
    answer = max(time_table)
    return answer