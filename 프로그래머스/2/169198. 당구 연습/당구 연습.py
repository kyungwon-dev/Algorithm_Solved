def solution(m, n, startX, startY, balls):
    answer = []
    for ball in balls:
        extended_ball = []
        if ball[0] == startX: # 같은 x값
            if ball[1] - startY > 0:
                extended_ball.append((ball[0], -ball[1]))
            else:
                extended_ball.append((ball[0], n + (n-ball[1])))
            extended_ball.append((m + (m - ball[0]), ball[1]))
            extended_ball.append((-ball[0], ball[1]))
        elif ball[1] == startY:
            if ball[0] - startX > 0:
                extended_ball.append((-ball[0], ball[1]))
            else:
                extended_ball.append((m + (m - ball[0]), ball[1]))
            extended_ball.append((ball[0], n + (n-ball[1])))
            extended_ball.append((ball[0], -ball[1]))
        else:
            extended_ball.append((m + (m - ball[0]), ball[1]))
            extended_ball.append((-ball[0], ball[1]))
            extended_ball.append((ball[0], n + (n-ball[1])))
            extended_ball.append((ball[0], -ball[1]))
        min_dis = 10**8
        # print(extended_ball)
        for eb in extended_ball:
            min_dis = min( min_dis, (startX - eb[0])**2 + (startY - eb[1])**2)
        answer.append(min_dis)
    return answer