import sys
sys.setrecursionlimit(100000)

def gcd(a, b):
    if a%b == 0:
        return b
    return gcd(b, a%b)

def solution(arrayA, arrayB):
    answer = 0
    if len(arrayA) == 1:
        if arrayA[0] == arrayB[0]:
            return 0
        return max(arrayA[0], arrayB[0])
    gcd_a = gcd(arrayA[0], arrayA[1])
    for i in range(2,len(arrayA)):
        gcd_a = gcd(gcd_a, arrayA[i])
    
    gcd_b = gcd(arrayB[0], arrayB[1])
    for i in range(2,len(arrayB)):
        gcd_b = gcd(gcd_b, arrayB[i])
        
    if gcd_a == 1:
        for a in arrayA:
            if a% gcd_b == 0:
                return 0
        return gcd_b
    elif gcd_b == 1:
        for b in arrayB:
            if b% gcd_a == 0:
                return 0
        return gcd_a
    else:
        is_b = True
        for a in arrayA:
            if a % gcd_b ==0:
                is_b = False
                break
        is_a = True
        for b in arrayB:
            if b % gcd_a ==0:
                is_a = False
                break
        if is_a and is_b:
            answer = max(gcd_a, gcd_b)
        elif is_a:
            answer = gcd_a
        elif is_b:
            answer = gcd_b
        else:
            answer = 0
    return answer