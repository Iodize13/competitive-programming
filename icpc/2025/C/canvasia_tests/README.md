# Canvasia — test data

66 test cases (`tests/01.in` … `tests/66.out`) for problem C, ICPC Thailand National Contest 2025.

## The problem, restated

Sort the tubes. Achieving contrast `D` means squeezing every brightness into some
window `[L, L+D]`, at a cost of

```
f(L) = Σ (L − x)  for x < L      +      Σ (x − L − D)  for x > L + D
```

`f` is convex and piecewise linear in `L`, and feasibility is monotone in `D`
(a wider window never costs more). So: binary search `D`, and for each `D` find
the best `L` by binary searching where the slope turns non-negative.
`O(n log n + log²(maxV)·log n)`.

**Costs reach ~10¹¹** (100 000 tubes × 10⁶ of travel), so every accumulator must be
64-bit. This is the single most likely reason for a fast solution to fail.

## What's in the box

| file | purpose |
|---|---|
| `tests/NN.in`, `tests/NN.out` | the test data |
| `solution.cpp` | reference solution (C++17). Slowest case: **13 ms** against the 1 s limit |
| `ref.py` | same algorithm in Python, used to produce the answers |
| `brute.py` | O(range²·n) brute force over every window |
| `verify.py` | independent checker — evaluates the cost at *every* breakpoint and asserts `cost(answer) ≤ k` **and** `cost(answer−1) > k` |
| `gen.py` | regenerates the whole suite (seeded, deterministic) |
| `validate.py` | input/output format and constraint checker |
| `catch_report.py` | runs known-wrong solutions and reports which tests expose them |
| `manifest.txt` | one line per test |

## How the answers were checked

1. `ref.py` vs `brute.py` on **4 000 random small inputs** — no mismatches.
2. All four statement samples reproduce exactly.
3. `verify.py` re-derives every answer with a different algorithm and asserts
   minimality, not just achievability — all 66 pass.
4. `solution.cpp` reproduces all 66 `.out` files.
5. `validate.py` confirms every file is well-formed and inside the constraints.

## Does the suite have teeth?

`catch_report.py` runs five plausible wrong solutions:

| wrong approach | tests that catch it |
|---|---|
| Only anchors the window at an existing brightness | 8 (first at **17**) |
| Assumes the window is centred on the median | 32 (first at **02**) |
| Assumes each unit of contrast costs 2 | 43 (first at **01**) |
| Assumes budget converts 1:1 into contrast | 25 (first at **01**) |
| 32-bit overflow in the cost sum | 12 (first at **47**) |

Note the first group: the optimal window's edges often sit at *no* input value at
all. On test 22 (`k=4`, tubes `2 7 7`) the answer is 1, using the window `[6,7]` —
6 is not a brightness anywhere in the input. Tests 22–29 exist purely for this.

## Running it

```bash
g++ -O2 -o solution solution.cpp
for f in tests/*.in; do
  diff <(./solution < "$f") "${f%.in}.out" > /dev/null || echo "WRONG: $f"
done

python3 verify.py     # re-derive every answer independently
python3 validate.py   # format + constraints
python3 gen.py        # regenerate from scratch (seed 20250907)
```

Checker: plain single-integer comparison, trailing whitespace ignored.

## The cases

| # | n | k | answer | what it targets |
|---|---|---|---|---|
| | | | | **Statement samples** |
| 01 | 5 | 7 | 4 | Sample 1 from the statement |
| 02 | 4 | 10 | 3 | Sample 2 from the statement |
| 03 | 3 | 15 | 0 | Sample 3 from the statement (already zero contrast) |
| 04 | 2 | 3 | 96 | Sample 4 from the statement (budget far too small) |
| | | | | **Tiny inputs and boundaries** |
| 05 | 1 | 0 | 0 | n=1 with k=0, smallest legal input |
| 06 | 1 | 1000000000 | 0 | n=1 with max k and max value |
| 07 | 2 | 0 | 999999 | n=2, zero budget, widest possible spread |
| 08 | 2 | 999999 | 0 | n=2, budget exactly enough to reach contrast 0 |
| 09 | 2 | 999998 | 1 | n=2, one unit short of contrast 0 -> answer 1 |
| 10 | 2 | 1000000000 | 0 | n=2, budget far exceeds what is needed |
| 11 | 4 | 0 | 0 | All values equal, k=0 |
| 12 | 5 | 0 | 8 | k=0 on distinct values -> answer is raw max-min |
| 13 | 2 | 1 | 2 | Odd gap with tiny budget (integer/rounding check) |
| 14 | 2 | 2 | 1 | Odd gap, budget reaches contrast 1 |
| 15 | 2 | 3 | 0 | Odd gap, budget reaches contrast 0 |
| | | | | **Anti-heuristic traps** |
| 16 | 4 | 3 | 6 | Three tubes at the low end: pulling the single max is cheaper |
| 17 | 4 | 3 | 6 | Mirror image: pushing the single min is cheaper |
| 18 | 21 | 100 | 899 | 20 tubes vs 1 far outlier: move the outlier, not the crowd |
| 19 | 21 | 100 | 899 | Mirrored crowd/outlier case |
| 20 | 6 | 7 | 7 | Even split, budget not divisible by group size |
| 21 | 6 | 11 | 6 | Same shape, leftover budget after an even split |
| 22 | 3 | 4 | 1 | Optimal window's LEFT edge is not any input value |
| 23 | 6 | 3 | 15 | Optimal left edge off-array, sparse low tail |
| 24 | 6 | 15 | 7 | Optimal left edge off-array, with duplicates |
| 25 | 6 | 2 | 18 | Optimal window's RIGHT edge is not any input value |
| 26 | 5 | 14 | 3 | Optimal right edge off-array |
| 27 | 5 | 8 | 16 | Optimal right edge off-array, duplicated ends |
| 28 | 3 | 400 | 100 | Scaled-up off-array left edge |
| 29 | 5 | 1400 | 300 | Scaled-up off-array right edge |
| 30 | 3 | 1000000000 | 0 | Small n, huge spread, budget makes contrast 0 easy |
| 31 | 7 | 90 | 0 | Budget exactly equals the cost of full collapse -> 0 |
| 32 | 7 | 89 | 1 | One unit below the full-collapse cost |
| 33 | 35 | 400 | 820 | Two clusters of unequal size, budget favours the small one |
| 34 | 35 | 400 | 820 | Same clusters, mirrored sizes |
| 35 | 4 | 1000000 | 499999 | Flat cost region (balanced ends) at large scale |
| 36 | 4 | 4 | 0 | Even n: collapse cost exactly equals k -> 0 |
| 37 | 4 | 3 | 1 | Even n: one unit below the collapse cost -> 1 |
| | | | | **Structured mid-size** |
| 38 | 1000 | 0 | 999 | Sorted ascending 1..1000, k=0 |
| 39 | 1000 | 50000 | 553 | Sorted ascending 1..1000, mid budget |
| 40 | 1000 | 250000 | 0 | Strictly DESCENDING input (input is not pre-sorted) |
| 41 | 500 | 12345 | 0 | Random small values, mid budget |
| 42 | 1000 | 1000000000 | 0 | Random wide values, large budget |
| 43 | 1000 | 5000000 | 896864 | Heavy tail: dense low cluster plus far scattered outliers |
| 44 | 2000 | 10000000 | 0 | Tight Gaussian cluster, budget large relative to spread |
| | | | | **Maximum size / stress / overflow** |
| 45 | 100000 | 0 | 0 | n=1e5 all equal, k=0 |
| 46 | 100000 | 1000000000 | 0 | n=1e5 all at max value, max k |
| 47 | 100000 | 0 | 999992 | n=1e5 uniform random, k=0 |
| 48 | 100000 | 1 | 999966 | n=1e5 uniform random, k=1 |
| 49 | 100000 | 1000000000 | 799151 | n=1e5 uniform random, max k |
| 50 | 100000 | 500000000 | 856830 | n=1e5 uniform random, half budget |
| 51 | 100000 | 0 | 999999 | n=1e5 split between the two extremes, k=0 |
| 52 | 100000 | 1000000000 | 979999 | n=1e5 extremes split, max k -- total cost ~5e10 OVERFLOWS 32-bit |
| 53 | 100000 | 1000000000 | 0 | n=1e5, one lone low outlier, max k (cheap fix, 64-bit sums) |
| 54 | 100000 | 999999 | 0 | Lone outlier, budget exactly enough -> 0 |
| 55 | 100000 | 999998 | 1 | Lone outlier, one unit short -> 1 |
| 56 | 100000 | 1000000000 | 0 | n=1e5, one lone high outlier, max k (drag the outlier, not the crowd) |
| 57 | 100000 | 1000000000 | 800623 | n=1e5 pre-sorted ascending, max k |
| 58 | 100000 | 1000000000 | 799919 | n=1e5 pre-sorted descending, max k |
| 59 | 100000 | 0 | 1 | n=1e5 of only 1s and 2s, k=0 -> 1 |
| 60 | 100000 | 1000000000 | 979992 | n=1e5 from four extreme buckets, max k |
| 61 | 100000 | 1000000000 | 0 | n=1e5 in a narrow high band, max k -> 0 |
| 62 | 100000 | 1000000000 | 557159 | n=1e5 log-uniform (geometric) spread, max k |
| 63 | 100000 | 300000000 | 993000 | n=1e5 bimodal, budget between the two clusters' costs |
| 64 | 99999 | 1000000000 | 800232 | n=99999 (odd count) uniform random, max k |
| 65 | 100000 | 1000000000 | 0 | Max n: collapse costs exactly 1e9 = k -> 0 (tightest 64-bit boundary) |
| 66 | 100000 | 999999999 | 1 | Max n: one unit below that boundary -> 1 |
## A note on the statement

The rules say a tube may be changed to *any* integer, with no lower bound, but
since every optimal window lies inside `[min, max]` of the input, going below 1 or
above 10⁶ is never useful — the data does not depend on how you read that.
