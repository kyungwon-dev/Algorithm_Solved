def solution(enroll, referral, seller, amount):
    answer = []
    employee_level = {
        e : 0 for e in enroll
    }
    employee_level["-"] = -1
    for i in range(len(enroll)):
        if referral[i] != "-":
            employee_level[enroll[i]] = employee_level[referral[i]] +1

    employee_dict = {
        e : [r, 0, 0] for e, r in zip(enroll, referral)
    }
    
    s_m = []
    for s,a in zip(seller, amount):
        s_m.append([s,a*100])
    
    employee_list = sorted(employee_dict.items(), key= lambda x : -(employee_level[x[1][0]]))
    employee_list = sorted(s_m, key= lambda x : -(employee_level[s]))

    employee_dict["-"] = ["END", 0, 0]

    for e in employee_list:
        s , m = e
        
        r = employee_dict[s][0]
        m = e[1]

        employee_dict[s][1] += m
        fee = m * 1 // 10
        employee_dict[s][1] -= m * 1 // 10

        prev, next = s, r
        while next!= '-':
            employee_dict[next][2] += fee
            fee = fee * 1 // 10
            if fee == 0:
                break
            employee_dict[next][2] -= fee
            prev, next = next, employee_dict[next][0]

            
    for e in employee_dict.values():
        if e[0] == "END":
            continue
        answer.append(e[1] + e[2])
    return answer