// Canvasia -- reference solution.
//
// Binary search the answer D. Feasibility is monotone: any window wider than a
// feasible one is at most as expensive. For a fixed D the cost of forcing every
// tube into [L, L+D],
//     f(L) = sum_{x < L} (L - x) + sum_{x > L+D} (x - L - D),
// is convex and piecewise linear in L, so its minimum is found by binary
// searching for the point where the slope stops being negative.
//
// O(n log n + log(maxV) * log(maxV) * log n).
// NOTE: costs reach ~1e11, so every accumulator must be 64-bit.

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long k;
    if (scanf("%d %lld", &n, &k) != 2) return 0;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
    sort(a.begin(), a.end());

    vector<long long> pref(n + 1, 0);
    for (int i = 0; i < n; i++) pref[i + 1] = pref[i] + a[i];

    auto cost = [&](long long L, long long D) -> long long {
        long long R = L + D;
        int i = int(lower_bound(a.begin(), a.end(), L) - a.begin());
        long long c = (long long)i * L - pref[i];
        int j = int(upper_bound(a.begin(), a.end(), R) - a.begin());
        c += (pref[n] - pref[j]) - (long long)(n - j) * R;
        return c;
    };

    auto mincost = [&](long long D) -> long long {
        long long lo = a[0], hi = max(a[0], a[n - 1] - D);
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (cost(mid, D) <= cost(mid + 1, D)) hi = mid;
            else lo = mid + 1;
        }
        return cost(lo, D);
    };

    long long lo = 0, hi = a[n - 1] - a[0];
    while (lo < hi) {
        long long mid = lo + (hi - lo) / 2;
        if (mincost(mid) <= k) hi = mid;
        else lo = mid + 1;
    }
    printf("%lld\n", lo);
    return 0;
}
