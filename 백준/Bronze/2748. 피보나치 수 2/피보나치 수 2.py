fibo = [0]*91
fibo[1] = 1
for i in range(2,91):
    fibo[i] = fibo[i-1] + fibo[i-2]
print(fibo[int(input())])