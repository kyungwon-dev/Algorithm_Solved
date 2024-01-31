def solution(rank, attendance):
    answer = 0
    nums = 10000
    rank_dict = {}
    index =0
    for r, a in zip(rank, attendance):
        rank_dict[r] = [index, a]
        index+=1
    rank_dict = dict(sorted(rank_dict.items(), key = lambda item: item[0]))
    # print(rank_dict)
    for k, v in rank_dict.items():
        if v[1]:
            answer = answer + (v[0] * nums)
            nums =int(nums/100)
        if nums ==0:
            break
    return answer