import sys


def brute(n, k, a):
    lo_v, hi_v = min(a), max(a)
    best = hi_v - lo_v
    # optimal window always lies inside [min, max]; pad anyway for safety
    for L in range(lo_v - 3, hi_v + 4):
        for R in range(L, hi_v + 4):
            c = 0
            for x in a:
                if x < L:
                    c += L - x
                elif x > R:
                    c += x - R
            if c <= k:
                best = min(best, R - L)
    return best


def main():
    data = sys.stdin.buffer.read().split()
    n = int(data[0]); k = int(data[1])
    a = list(map(int, data[2:2 + n]))
    print(brute(n, k, a))


if __name__ == "__main__":
    main()
