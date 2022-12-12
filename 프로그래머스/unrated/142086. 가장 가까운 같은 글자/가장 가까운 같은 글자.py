def solution(s):
    alphabet = [-1 for _ in range(ord('z') - ord('a') + 1)]
    answer = []
    for i in range(len(s)):
        ch = ord(s[i]) - ord('a')
        if alphabet[ch] != -1:
            answer.append(i - alphabet[ch])
        else:
            answer.append(alphabet[ch])
        alphabet[ch] = i
    return answer