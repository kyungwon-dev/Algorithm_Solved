def solution(num_str):
    answer = 0
    for num in list(num_str):
        answer += ord(num) - ord('0')
    return answer