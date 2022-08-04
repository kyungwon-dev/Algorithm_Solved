students = [True] * 30
for i in range(28):
    student = int(input())
    students[student-1] = False
for idx, val in enumerate(students):
    if val:
        print(idx+1)
