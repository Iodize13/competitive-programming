import sys
from bisect import bisect_left, bisect_right


def min_contrast(n, k, a):
    """Minimum achievable (max-min) after paying total cost <= k.

    Binary search the answer D (feasibility is monotone: a wider window is
    never more expensive). For a fixed D, cost(L) = sum of pulls into the
    window [L, L+D] is convex piecewise-linear in L, so the optimal L is
    found by binary searching the slope change.
    """
    a = sorted(a)
    pref = [0] * (n + 1)
    for i, x in enumerate(a):
        pref[i + 1] = pref[i] + x
    lo_v, hi_v = a[0], a[-1]

    def cost(L, D):
        R = L + D
        i = bisect_left(a, L)               # elements strictly below L
        c = i * L - pref[i]
        j = bisect_right(a, R)              # elements <= R
        c += (pref[n] - pref[j]) - (n - j) * R
        return c

    def mincost(D):
        lo, hi = lo_v, max(lo_v, hi_v - D)
        while lo < hi:
            mid = (lo + hi) // 2
            if cost(mid, D) <= cost(mid + 1, D):
                hi = mid
            else:
                lo = mid + 1
        return cost(lo, D)

    lo, hi = 0, hi_v - lo_v
    while lo < hi:
        mid = (lo + hi) // 2
        if mincost(mid) <= k:
            hi = mid
        else:
            lo = mid + 1
    return lo


def main():
    data = sys.stdin.buffer.read().split()
    n = int(data[0]); k = int(data[1])
    a = list(map(int, data[2:2 + n]))
    sys.stdout.write(str(min_contrast(n, k, a)) + "\n")


if __name__ == "__main__":
    main()
