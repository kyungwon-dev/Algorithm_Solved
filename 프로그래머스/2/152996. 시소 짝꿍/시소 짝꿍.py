def solution(weights):
    answer = 0
    weights.sort()
    weight_dict = {}
    for weight in weights:
        if weight in weight_dict:
            weight_dict[weight]+=1
        else:
            weight_dict[weight] = 1
    # print(weight_dict)
    for k in weight_dict.keys():
        # 동일한 무게가 2개 이상인 경우 같은 쌍으로 취급
        answer += int (weight_dict[k] * (weight_dict[k] - 1) / 2) 
        if k*2 in weight_dict:
            answer += ( weight_dict[k*2] * weight_dict[k])
        if k%2 == 0 and int(k/2*3) in weight_dict:
            answer += ( weight_dict[int(k/2*3)] * weight_dict[k])
        if k%3 == 0 and int(k/3*4) in weight_dict:
            answer += ( weight_dict[int(k/3*4)] * weight_dict[k])
    
    return answer