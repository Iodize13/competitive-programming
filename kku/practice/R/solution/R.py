while True:
    s = input().split()
    n = int(s[0])
    m = int(s[1])
    if n == -1 and m == -1:
        break
    if n > m:
        print("COE")
    elif n < m:
        print("CP")
    else:
        print("DRAW")
