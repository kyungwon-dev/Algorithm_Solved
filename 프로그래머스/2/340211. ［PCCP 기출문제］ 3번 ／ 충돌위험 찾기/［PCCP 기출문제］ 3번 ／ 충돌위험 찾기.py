def solution(points, routes):
    answer = 0
    robot = {
        i+1 : [] for i in range(len(routes))
    }
    # 
    

    for i in range(len(routes)):
        for j in range(0, len(routes[i])-1):
            sr, sc = points[routes[i][j]-1]
            dr, dc = points[routes[i][j+1]-1]
            if j == 0:
                robot[i+1].append([sr,sc]) # 시작점
            while sr != dr:
                if sr > dr:
                    sr-=1
                else:
                    sr+=1
                robot[i+1].append([sr,sc]) # r방향 변경

            while sc != dc:
                if sc > dc:
                    sc-=1
                else:
                    sc+=1
                robot[i+1].append([sr,sc])
    # print(robot)
    time = 0
    isRobot = True
    while isRobot:
        moving = []
        crash = []
        for k,v in robot.items():
            if len(v) <= time:
                continue
            moving.append(v[time])
        moving.sort(key=lambda x: (x[0], x[1]))
        if len(moving) <= 1:
            break
        for i in range(1, len(moving)):
            if moving[i-1][0] == moving[i][0] and moving[i-1][1] == moving[i][1] and moving[i] not in crash:
                answer +=1
                crash.append(moving[i])
        time+=1

    return answer