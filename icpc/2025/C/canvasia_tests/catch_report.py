"""Run several plausible-but-wrong solutions against the suite and report
which test files expose each of them."""
import glob
import numpy as np


def load(path):
    with open(path) as f:
        n, k = map(int, f.readline().split())
        a = np.array(f.readline().split(), dtype=np.int64)
    return n, k, a


def costs_at(a, pref, n, L, D):
    L = np.asarray(L, dtype=np.int64)
    R = L + D
    i = np.searchsorted(a, L, side="left")
    j = np.searchsorted(a, R, side="right")
    return (i * L - pref[i]) + ((pref[n] - pref[j]) - (n - j) * R)


def wa_left_edge_only(n, k, a):
    """Only considers windows whose left edge is an existing brightness."""
    a = np.sort(a); pref = np.zeros(n + 1, dtype=np.int64); np.cumsum(a, out=pref[1:])
    lo, hi = 0, int(a[-1] - a[0])
    cand = np.unique(a)
    while lo < hi:
        mid = (lo + hi) // 2
        if costs_at(a, pref, n, cand, mid).min() <= k: hi = mid
        else: lo = mid + 1
    return lo


def wa_median_window(n, k, a):
    """Assumes the optimal window is centred on the median."""
    a = np.sort(a); pref = np.zeros(n + 1, dtype=np.int64); np.cumsum(a, out=pref[1:])
    med = int(a[n // 2])
    lo, hi = 0, int(a[-1] - a[0])
    while lo < hi:
        mid = (lo + hi) // 2
        if costs_at(a, pref, n, np.array([med - mid // 2]), mid).min() <= k: hi = mid
        else: lo = mid + 1
    return lo


def wa_two_per_unit(n, k, a):
    """Greedy myth: every unit of contrast costs 2 (one off each end)."""
    return max(0, int(a.max() - a.min()) - k // 2)


def wa_spread_minus_k(n, k, a):
    """Greedy myth: budget converts 1:1 into contrast."""
    return max(0, int(a.max() - a.min()) - k)


def wa_int32(n, k, a):
    """Correct algorithm, but cost sums wrap at 32 bits."""
    a = np.sort(a); pref = np.zeros(n + 1, dtype=np.int64); np.cumsum(a, out=pref[1:])

    def mc(D):
        cand = np.unique(np.concatenate([a, a - D]))
        cand = cand[(cand >= a[0]) & (cand <= max(a[0], a[-1] - D))]
        if cand.size == 0: cand = a[:1]
        c = costs_at(a, pref, n, cand, D)
        return int(np.int32(np.clip(c, -2**63, 2**63 - 1) % 2**32 - (c % 2**32 >= 2**31) * 2**32).min())

    lo, hi = 0, int(a[-1] - a[0])
    while lo < hi:
        mid = (lo + hi) // 2
        if mc(mid) <= k: hi = mid
        else: lo = mid + 1
    return lo


WRONG = [
    ("only anchors window at an input value", wa_left_edge_only),
    ("assumes window is centred on the median", wa_median_window),
    ("assumes each unit of contrast costs 2", wa_two_per_unit),
    ("assumes budget converts 1:1 to contrast", wa_spread_minus_k),
    ("32-bit overflow in the cost sum", wa_int32),
]

files = sorted(glob.glob("tests/*.in"))
for label, fn in WRONG:
    caught = []
    for inp in files:
        n, k, a = load(inp)
        exp = int(open(inp[:-3] + ".out").read())
        try:
            got = fn(n, k, a.copy())
        except Exception:
            got = None
        if got != exp:
            caught.append(inp.split("/")[-1][:2])
    print("%-45s caught by %2d/%d tests: %s" %
          (label, len(caught), len(files), ", ".join(caught[:12]) + (" ..." if len(caught) > 12 else "")))
