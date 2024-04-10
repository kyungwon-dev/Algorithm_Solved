def solution(data, col, row_begin, row_end):
    answer = -1
    data.sort(key = lambda x : (x[col-1], -x[0]))
    for i in range(row_begin-1, row_end):
        nums = sum([x% (i+1) for x in data[i]])
        if answer == -1:
            answer = nums
        else:
            answer = answer ^ nums
        
    return answer