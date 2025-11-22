T = int(input())
for i in range(T):
    N = int(input())
    M = N + 1
    # This is to avoid integer overflow
    if N%2 == 0:
        N = int(N/2)
    else:
        M = int(M/2)
    print(N*M)
