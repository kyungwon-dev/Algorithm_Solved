import sys
while True:
    string = input()
    if string == ".":
        break
    bracket = []
    is_balanced = True
    for s in string:
        if s == "[" or s == "(":
            bracket.append(s)
        elif s == "]" or s == ")":
            if not bracket:
                is_balanced = False
                break
            top = bracket.pop()
            if (top == "[" and s == ")") or (top == "(" and s == "]"):
                is_balanced = False
                break
    if bracket:
        is_balanced = False
    print("yes" if is_balanced else "no")