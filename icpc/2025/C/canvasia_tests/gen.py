import os
import random
from ref import min_contrast

OUT = "tests"
os.makedirs(OUT, exist_ok=True)
random.seed(20250907)

CASES = []  # (n, k, array, purpose)


def add(k, a, purpose):
    CASES.append((len(a), k, list(a), purpose))


def zero_cost(a):
    """Cheapest way to collapse everything to one value (median target)."""
    s = sorted(a)
    m = s[len(s) // 2]
    return sum(abs(x - m) for x in s)


# ---------------------------------------------------------------- samples
add(7, [1, 2, 4, 8, 10], "Sample 1 from the statement")
add(10, [1, 5, 9, 13], "Sample 2 from the statement")
add(15, [10, 10, 10], "Sample 3 from the statement (already zero contrast)")
add(3, [1, 100], "Sample 4 from the statement (budget far too small)")

# ------------------------------------------------------- tiny / boundary
add(0, [1], "n=1 with k=0, smallest legal input")
add(10**9, [10**6], "n=1 with max k and max value")
add(0, [1, 10**6], "n=2, zero budget, widest possible spread")
add(999999, [1, 10**6], "n=2, budget exactly enough to reach contrast 0")
add(999998, [1, 10**6], "n=2, one unit short of contrast 0 -> answer 1")
add(10**9, [1, 10**6], "n=2, budget far exceeds what is needed")
add(0, [5, 5, 5, 5], "All values equal, k=0")
add(0, [7, 3, 9, 1, 4], "k=0 on distinct values -> answer is raw max-min")
add(1, [1, 4], "Odd gap with tiny budget (integer/rounding check)")
add(2, [1, 4], "Odd gap, budget reaches contrast 1")
add(3, [1, 4], "Odd gap, budget reaches contrast 0")

# ----------------------------------------------- anti-heuristic / traps
add(3, [1, 1, 1, 10], "Three tubes at the low end: pulling the single max is cheaper")
add(3, [1, 10, 10, 10], "Mirror image: pushing the single min is cheaper")
add(100, [1] * 20 + [1000], "20 tubes vs 1 far outlier: move the outlier, not the crowd")
add(100, [1] + [1000] * 20, "Mirrored crowd/outlier case")
add(7, [1, 1, 1, 10, 10, 10], "Even split, budget not divisible by group size")
add(11, [1, 1, 1, 10, 10, 10], "Same shape, leftover budget after an even split")
add(4, [2, 7, 7], "Optimal window's LEFT edge is not any input value")
add(3, [5, 17, 20, 21, 22, 23], "Optimal left edge off-array, sparse low tail")
add(15, [1, 3, 13, 15, 15, 17], "Optimal left edge off-array, with duplicates")
add(2, [5, 6, 11, 14, 16, 25], "Optimal window's RIGHT edge is not any input value")
add(14, [12, 13, 14, 22, 23], "Optimal right edge off-array")
add(8, [3, 6, 6, 24, 24], "Optimal right edge off-array, duplicated ends")
add(400, [200, 700, 700], "Scaled-up off-array left edge")
add(1400, [1200, 1300, 1400, 2200, 2300], "Scaled-up off-array right edge")
add(10**9, [1, 500000, 10**6], "Small n, huge spread, budget makes contrast 0 easy")
_a = [3, 9, 14, 14, 20, 41, 55]
add(zero_cost(_a), _a, "Budget exactly equals the cost of full collapse -> 0")
add(zero_cost(_a) - 1, _a, "One unit below the full-collapse cost")
add(400, [100] * 30 + [1000] * 5, "Two clusters of unequal size, budget favours the small one")
add(400, [100] * 5 + [1000] * 30, "Same clusters, mirrored sizes")
add(10**6, [1, 1, 10**6, 10**6], "Flat cost region (balanced ends) at large scale")

add(4, [1, 2, 3, 4], "Even n: collapse cost exactly equals k -> 0")
add(3, [1, 2, 3, 4], "Even n: one unit below the collapse cost -> 1")

# ------------------------------------------------- structured, mid-size
asc = list(range(1, 1001))
add(0, asc, "Sorted ascending 1..1000, k=0")
add(50000, asc, "Sorted ascending 1..1000, mid budget")
add(250000, list(range(1000, 0, -1)),
    "Strictly DESCENDING input (input is not pre-sorted)")
add(12345, [random.randint(1, 100) for _ in range(500)], "Random small values, mid budget")
add(10**9, [random.randint(1, 10**6) for _ in range(1000)], "Random wide values, large budget")
_heavy = [random.randint(1, 50) for _ in range(900)] + [random.randint(900000, 10**6) for _ in range(100)]
add(5 * 10**6, _heavy, "Heavy tail: dense low cluster plus far scattered outliers")
_gauss = [min(10**6, max(1, int(random.gauss(500000, 300)))) for _ in range(2000)]
add(10**7, _gauss, "Tight Gaussian cluster, budget large relative to spread")

# ----------------------------------------------------- max-size / stress
N = 10**5
add(0, [1] * N, "n=1e5 all equal, k=0")
add(10**9, [10**6] * N, "n=1e5 all at max value, max k")
add(0, [random.randint(1, 10**6) for _ in range(N)], "n=1e5 uniform random, k=0")
add(1, [random.randint(1, 10**6) for _ in range(N)], "n=1e5 uniform random, k=1")
add(10**9, [random.randint(1, 10**6) for _ in range(N)], "n=1e5 uniform random, max k")
add(10**9 // 2, [random.randint(1, 10**6) for _ in range(N)], "n=1e5 uniform random, half budget")
add(0, [1, 10**6] * (N // 2), "n=1e5 split between the two extremes, k=0")
add(10**9, [1, 10**6] * (N // 2),
    "n=1e5 extremes split, max k -- total cost ~5e10 OVERFLOWS 32-bit")
add(10**9, [10**6] * (N - 1) + [1],
    "n=1e5, one lone low outlier, max k (cheap fix, 64-bit sums)")
add(999999, [10**6] * (N - 1) + [1], "Lone outlier, budget exactly enough -> 0")
add(999998, [10**6] * (N - 1) + [1], "Lone outlier, one unit short -> 1")
add(10**9, [1] * (N - 1) + [10**6],
    "n=1e5, one lone high outlier, max k (drag the outlier, not the crowd)")
add(10**9, sorted(random.randint(1, 10**6) for _ in range(N)),
    "n=1e5 pre-sorted ascending, max k")
add(10**9, sorted((random.randint(1, 10**6) for _ in range(N)), reverse=True),
    "n=1e5 pre-sorted descending, max k")
add(0, [random.randint(1, 2) for _ in range(N)], "n=1e5 of only 1s and 2s, k=0 -> 1")
add(10**9, [random.choice([1, 2, 999999, 10**6]) for _ in range(N)],
    "n=1e5 from four extreme buckets, max k")
add(10**9, [random.randint(999990, 10**6) for _ in range(N)],
    "n=1e5 in a narrow high band, max k -> 0")
_geo = [min(10**6, int(2 ** random.uniform(0, 20))) for _ in range(N)]
add(10**9, _geo, "n=1e5 log-uniform (geometric) spread, max k")
_bimodal = [random.randint(1, 1000) for _ in range(N // 2)] + \
           [random.randint(999000, 10**6) for _ in range(N // 2)]
random.shuffle(_bimodal)
add(3 * 10**8, _bimodal, "n=1e5 bimodal, budget between the two clusters' costs")
add(10**9, [random.randint(1, 10**6) for _ in range(N - 1)],
    "n=99999 (odd count) uniform random, max k")
add(10**9, [490000] * (N // 2) + [510000] * (N // 2),
    "Max n: collapse costs exactly 1e9 = k -> 0 (tightest 64-bit boundary)")
add(10**9 - 1, [490000] * (N // 2) + [510000] * (N // 2),
    "Max n: one unit below that boundary -> 1")

# ------------------------------------------------------------ write out
lines = []
for idx, (n, k, a, purpose) in enumerate(CASES, start=1):
    assert 1 <= n <= 10**5, (idx, n)
    assert 0 <= k <= 10**9, (idx, k)
    assert all(1 <= x <= 10**6 for x in a), idx
    assert all(isinstance(x, int) for x in a), idx
    name = "%02d" % idx
    with open(os.path.join(OUT, name + ".in"), "w") as f:
        f.write("%d %d\n" % (n, k))
        f.write(" ".join(map(str, a)) + "\n")
    ans = min_contrast(n, k, a)
    with open(os.path.join(OUT, name + ".out"), "w") as f:
        f.write("%d\n" % ans)
    lines.append((name, n, k, ans, purpose))

with open("manifest.txt", "w") as f:
    for name, n, k, ans, purpose in lines:
        f.write("%s | n=%-6d k=%-11d answer=%-8d | %s\n" % (name, n, k, ans, purpose))

print("wrote %d cases" % len(lines))
for name, n, k, ans, purpose in lines:
    print("%s  n=%-6d k=%-11d ans=%-8d %s" % (name, n, k, ans, purpose))
