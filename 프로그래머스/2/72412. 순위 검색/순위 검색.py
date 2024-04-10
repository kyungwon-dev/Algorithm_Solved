import re
import bisect

def solution(infos, queries):
    
    
    info_dict = {}
    answer = []
        
    for info in infos:
        info = info.split(' ')
        k = info[0][0] + info[1][0] + info[2][0]+ info[3][0]
        if k not in info_dict:
            info_dict[k] = [int(info[4])]
        else:
            info_dict[k].append(int(info[4]))
    for info in info_dict:
        info_dict[info].sort()

    for query in queries:
        query = query.split(" and ")
        k = (query[0][0] + query[1][0] + query[2][0]+ query[3][0]).replace('-', "\w")
        score = int(query[3].split(" ")[1])
        r = re.compile(k)
        correct_keys = list(filter(r.match,[k for k in info_dict.keys()]))
        cnt = 0
        for correct_key in correct_keys:
            cnt = cnt + (len(info_dict[correct_key]) -  bisect.bisect_left(info_dict[correct_key], int(score)) )
            pass
        #     for i in range(len(info_dict[correct_key])):
        #         if score <= info_dict[correct_key][i]:
        #             cnt += len(info_dict[correct_key]) - i
        #             break
        # # print(cnt)

        answer.append(cnt)
        
        
    
    return answer