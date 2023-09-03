def solution(num_list):
    answer = 0
    sum_of_square = sum(num_list)
    sum_of_square = sum_of_square * sum_of_square
    mul = 1
    for num in num_list:
        mul *= num
    return 1 if sum_of_square > mul else 0