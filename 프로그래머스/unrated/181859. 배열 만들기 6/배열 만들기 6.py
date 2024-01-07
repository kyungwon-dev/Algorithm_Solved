def solution(arr):
    answer = []
    for i in range(len(arr)):
        if not answer:
            answer.append(arr[i])
        else:
            if answer[-1] == arr[i]:
                answer.pop(len(answer)-1)
            else:
                answer.append(arr[i])
    if not answer:
        answer.append(-1)
    return answer