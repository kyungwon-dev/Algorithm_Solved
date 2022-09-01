import sys
N = int(sys.stdin.readline().strip())
meetings = [ list(map(int, sys.stdin.readline().strip().split())) for _ in range(N)]
meetings.sort(key=lambda x : x[0])
meetings.sort(key=lambda x : x[1])
max_meeting , meeting_end = 0 , 0
for i in range(len(meetings)):
    if meeting_end <= meetings[i][0]:
        meeting_end = meetings[i][1]
        max_meeting+=1
print(max_meeting)