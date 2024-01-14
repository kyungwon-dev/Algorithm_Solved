def solution(my_string, queries):
    answer = ''
    for q1, q2 in queries:
        mid = my_string[q1:q2+1]
        mid = mid[::-1]
        my_string = my_string[:q1] + mid + my_string[q2+1:]
    return my_string