import glob, re, sys
ok = True
for inp in sorted(glob.glob("tests/*.in")):
    raw = open(inp, "rb").read().decode()
    problems = []
    if not raw.endswith("\n") or raw.endswith("\n\n"): problems.append("trailing newline")
    lines = raw.rstrip("\n").split("\n")
    if len(lines) != 2: problems.append("expected 2 lines, got %d" % len(lines))
    else:
        if not re.fullmatch(r"\d+ \d+", lines[0]): problems.append("bad header line")
        if not re.fullmatch(r"\d+( \d+)*", lines[1]): problems.append("bad value line")
        n, k = map(int, lines[0].split()); a = list(map(int, lines[1].split()))
        if len(a) != n: problems.append("header says n=%d, found %d values" % (n, len(a)))
        if not 1 <= n <= 10**5: problems.append("n out of range")
        if not 0 <= k <= 10**9: problems.append("k out of range")
        if not all(1 <= x <= 10**6 for x in a): problems.append("brightness out of range")
    out = open(inp[:-3] + ".out", "rb").read().decode()
    if not re.fullmatch(r"\d+\n", out): problems.append("output not a single integer + newline")
    if problems:
        ok = False; print("FAIL %s: %s" % (inp, "; ".join(problems)))
print("all input/output files well-formed and within constraints" if ok else "FORMAT PROBLEMS")
sys.exit(0 if ok else 1)
