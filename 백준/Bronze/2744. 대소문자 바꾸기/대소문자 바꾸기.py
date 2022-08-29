strs = list(input())
for i in range(len(strs)):
    if strs[i].islower():
        strs[i] = strs[i].upper()
    else:
        strs[i] = strs[i].lower()
print("".join(strs))