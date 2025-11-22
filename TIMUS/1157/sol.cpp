// #pragma GCC optimize("O3,unroll-loops")
#include "bits/stdc++.h"

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define dbg(...) 42
#endif
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
#define fi first
#define se second
#define int long long
#define ll long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef vector<int> vi;
typedef pair<int, int> pii;
void solve();
const int di[4] = {0, 0, -1, 1};
const int dj[4] = {-1, 1, 0, 0};
const int N = 10'000 + 1;
vi a(N);
void init();

int32_t main() {
    send help

    init();
    solve();
}

void solve() {
    int n, m, k;
    cin >> m >> n >> k;
    int ans = 0;
    rep(l,1,N) {
        if (l-k >= 0 && a[l]==n && a[l-k]==m) {
            ans = l;
            break;
        }
    }

    cout << ans << '\n';
}

void init() {
    rep(i,1,N) {
        for (int j = 1; j * j <= i; j++) {
            if (i % j == 0) a[i]++;
        }
    }
}
