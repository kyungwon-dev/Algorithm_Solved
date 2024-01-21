str = input()
for s in str:
    if ord('A') <= ord(s) <= ord('Z'):
        print(chr(ord(s) - ord('A') + ord('a')), end="")
    else:
        print(chr(ord(s) - ord('a') + ord('A')), end="")