"""Independent check of every generated answer.

Different algorithm from ref.py on purpose: instead of binary searching the
slope, it evaluates the cost at EVERY breakpoint of the piecewise-linear cost
function (L = a_i and L = a_i - D), which is where the minimum must sit.
Then it asserts cost(answer) <= k and cost(answer-1) > k.
"""
import glob
import os
import sys
import numpy as np


def mincost(a_sorted, pref, D):
    n = len(a_sorted)
    cands = np.unique(np.concatenate([a_sorted, a_sorted - D]))
    lo_v, hi_v = a_sorted[0], a_sorted[-1]
    cands = cands[(cands >= lo_v) & (cands <= max(lo_v, hi_v - D))]
    if cands.size == 0:
        cands = np.array([lo_v], dtype=np.int64)
    L = cands.astype(np.int64)
    R = L + D
    i = np.searchsorted(a_sorted, L, side="left")
    low = i * L - pref[i]
    j = np.searchsorted(a_sorted, R, side="right")
    high = (pref[n] - pref[j]) - (n - j) * R
    return int((low + high).min())


def main():
    ok = True
    for inp in sorted(glob.glob("tests/*.in")):
        out = inp[:-3] + ".out"
        with open(inp) as f:
            n, k = map(int, f.readline().split())
            a = np.array(f.readline().split(), dtype=np.int64)
        ans = int(open(out).read().strip())
        assert len(a) == n, "%s: n mismatch" % inp
        a.sort()
        pref = np.zeros(n + 1, dtype=np.int64)
        np.cumsum(a, out=pref[1:])

        spread = int(a[-1] - a[0])
        problems = []
        if not (0 <= ans <= spread):
            problems.append("answer %d outside [0, %d]" % (ans, spread))
        if mincost(a, pref, ans) > k:
            problems.append("answer %d is NOT achievable within k=%d" % (ans, k))
        if ans > 0 and mincost(a, pref, ans - 1) <= k:
            problems.append("answer %d is not minimal (%d also fits)" % (ans, ans - 1))
        if problems:
            ok = False
            print("FAIL %s: %s" % (os.path.basename(inp), "; ".join(problems)))
        else:
            print("ok   %s  n=%-6d k=%-11d answer=%d" % (os.path.basename(inp), n, k, ans))
    print("\nALL VERIFIED" if ok else "\nPROBLEMS FOUND")
    return 0 if ok else 1


if __name__ == "__main__":
    sys.exit(main())
