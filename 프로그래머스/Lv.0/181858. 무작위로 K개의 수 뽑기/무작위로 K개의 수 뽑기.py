def solution(arr, k):
    nums = [False for _ in range(100001)]
    answer = []
    for a in arr:
        if nums[a]:
            continue
        nums[a] = True
        answer.append(a)
        k-=1
        if k==0:
            break
    answer.extend([-1] * k)
    return answer