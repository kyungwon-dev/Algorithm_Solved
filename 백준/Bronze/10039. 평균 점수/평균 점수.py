answer = 0
for i in range(5):
    score = int(input())
    answer = answer + (40 if score<40 else score)
print(answer //5)