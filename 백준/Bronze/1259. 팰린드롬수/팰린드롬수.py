while True:
    nums = input()
    if nums=="0":
        break;
    if nums == nums[::-1]:
        print("yes")
    else:
        print("no")