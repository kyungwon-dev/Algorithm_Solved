from itertools import product
def solution(users, emoticons):
    answer = []
    discounts = [60,70,80,90]
    discounts = list(product(discounts, repeat=len(emoticons)))
    
    for discount in discounts:
        total = [0,0]
        dis_emoticons = [[int(e //100 * d), d] for e,d in zip(emoticons, discount)]
        
        for user in users:
            price, subscribe = sum([d[0] for d in dis_emoticons if int(100 - user[0]) >= d[1]]),0 
            
            
            if price >= int(user[1]):
                total[0]+=1
            else:
                total[1]+=price
        answer.append(total)
    answer.sort(key = lambda x: (-x[0],-x[1]))
    return answer[0]