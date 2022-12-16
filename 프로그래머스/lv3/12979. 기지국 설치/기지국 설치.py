def solution(n, stations, w):
    answer = 0
    s = 2*w + 1
    s_stations = []
    d_stations = []
    if len(stations) == 0:
        return n // s + 1
    for station in stations:
        s_stations.append(station - w if station - w >= 1 else 1)
        d_stations.append(station + w if station + w <= n else n)

        if len(s_stations) > 1:
            if s_stations[-1] <= d_stations[-2] or s_stations[-1] == d_stations[-2] + 1:
                s_stations.pop()
                tmp = d_stations.pop()
                d_stations[-1] = tmp

    start = 1 

    for i in range(len(s_stations)):
        dest = s_stations[i]
        if dest == 1:
            start = d_stations[i] + 1
            continue
        answer += (dest - start) // s + (1 if (dest - start) % s != 0 else 0)
        start = d_stations[i] + 1
        
    if start <= n:
        answer += (n - start) // s + (1 if (n - start) % s != 0 else 0)
    if start == n:
        answer+=1
    return answer