from collections import deque
def solution(order):
    answer = 0
    order = deque(order)
    order_p = deque([])
    assistant = deque([])
    products = deque([i+1 for i in range(len(order))])
    
    while len(products)>0:
        if order[0] == products[0]:
            order.popleft()
            products.popleft()
            answer+=1

        else:
            assistant.append(products.popleft())
            
        while len(assistant) > 0 and assistant[-1] == order[0]:
            order.popleft()
            assistant.pop()
            answer+=1
            
    return answer