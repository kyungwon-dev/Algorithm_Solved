def solution(picture, k):
    answer = [''] * (len(picture) * k)
    for i in range(len(answer)):
        answer[i] = "".join([j*k for j in picture[int(i/k)]])
    return answer