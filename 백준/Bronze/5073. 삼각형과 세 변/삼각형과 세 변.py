import sys
input = sys.stdin.readline

# time limit = 1sec, memory limit = 128mb
# time complex = 10**3
while True:
    nums = sorted(list(map(int, input().strip().split())))
    i,j,k = nums
    if i+j+k == 0:
        break
    if i + j <= k:
        print("Invalid")
    elif i == k:
        print("Equilateral")
    elif i != j and j != k:
        print("Scalene")
    else:
        print("Isosceles")

