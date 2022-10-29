
def solution(ingredients):
    answer = 0
    stack = []
    is_possible = [False for _ in range(3)]
    # 1 : 빵, 2: 야채, 3:고기
    for ingredient in ingredients:
        stack.append(ingredient)
        
        if ingredient == 1:
            if len(stack) < 4:
                continue
            else:
                nums = stack[len(stack)-4:]
                nums = nums[0]*1000 + nums[1]*100 + nums[2]*10 + nums[3]*1
                if nums == 1231:
                    answer+=1
                    for i in range(4):
                        stack.pop()
                    
    return answer