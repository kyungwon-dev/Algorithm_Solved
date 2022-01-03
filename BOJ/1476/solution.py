import sys

def calc_inverse(x:int, y:int, z:int) -> int:
    for i in range(z):
        if( ((i+1) * x * y % z) == 1):
            return i+1

E, S, M = map(int, sys.stdin.readline().split())
# rs = f"{E}{S}{M}"
a1 = calc_inverse(19,28,15)
a2 = calc_inverse(19,15,28)
a3 = calc_inverse(28,15,19)

a = 28*19*(E-1)*a1 + 15*19*(S-1)*a2 + 15*28*(M-1)*a3
print(a%(15*19*28)+1)
