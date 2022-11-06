def solution(k, ranges):
    nums = [[0,float(k)]]
    sums = [0]
    while k!=1:
        if k%2 == 0:
            k =k / 2
        else:
            k =k * 3 + 1.0
        nums.append([nums[-1][0]+1, k])
        sums.append( sums[-1] + (nums[-1][1] + nums[-2][1]) /2 ) 
    # print(*nums)
    # print(*sums)
    answer = []
    for left, right in ranges:
        if left+1 > len(sums) + right:
            answer.append(-1.0)
        else:
            l_sum = sums[-1] - sums[left]
            r_sum = sums[-1] - sums[len(sums)-1 + right]
            answer.append(l_sum - r_sum)
    
    return answer