def solution(storey):
    answer = 0
    storey = list(str(storey))
    
    storey.insert(0, "0")
    storey.reverse()
    
    adder = 0
    for i in range(len(storey)):
        s = int(storey[i]) + adder
        adder = 0
        
        if(s>=5):
            answer +=(10 - s)
            adder = 1
        else:
            answer +=( s - 0)
        
    answer1 = 0
    adder = 0
    for i in range(len(storey)):
        s = int(storey[i]) + adder
        adder = 0
        
        if(s>5):
            answer1 +=(10 - s)
            adder = 1
        else:
            answer1 +=( s - 0)
    
        
    return min(answer, answer1)