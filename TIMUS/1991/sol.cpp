// #pragma GCC optimize("O3,unroll-loops")
#include "bits/stdc++.h"

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define dbg(...) 42
#endif
#define f first
#define s second
#define int long long
#define ll long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef vector<int> vi;
typedef pair<int, int> pii;
const int di[4] = {0, 0, -1, 1};
const int dj[4] = {-1, 1, 0, 0};



const bool TC = 0;
void solve() {
    int n, k;
    scanf("%lld%lld", &n, &k);
    vi a(n);
    int b = 0, c = 0;
    for (auto &x: a) {
        scanf("%lld", &x);
        b += max(0ll, x - k);
        c += max(0ll, k - x);
    }

    printf("%lld %lld\n", b, c);
}

int32_t main() {
    int tt = 1;
    if (TC) cin >> tt;
    while (tt--) solve();
}
