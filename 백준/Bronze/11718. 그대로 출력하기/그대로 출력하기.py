strings = []
while True:
    try:
        x=input()
    except EOFError:
        break
    strings.append(x)
for string in strings:
    print(string)
    