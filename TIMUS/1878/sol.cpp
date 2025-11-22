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
    int n = 4;
    vector<vi> g(n, vi(n));
    rep(i,0,n) {
        rep(j,0,n) {
            cin >> g[i][j];
        }
    }

    int l0i[] = {0,0,3,3};
    int l0j[] = {0,3,3,0};
    int l1i[] = {0,1,3,2};
    int l1j[] = {1,3,2,0};
    int l2i[] = {1,0,2,3};
    int l2j[] = {0,2,3,1};
    int l3i[] = {1,1,2,2};
    int l3j[] = {1,2,2,1};
    vi pos;
    rep(dir,0,n) {
        if (g[l0i[dir]][l0j[dir]] == 1) pos.push_back(dir);
    }
    rep(dir,0,n) {
        if (g[l1i[dir]][l1j[dir]] == 1) pos.push_back(dir);
    }
    rep(dir,0,n) {
        if (g[l2i[dir]][l2j[dir]] == 1) pos.push_back(dir);
    }
    rep(dir,0,n) {
        if (g[l3i[dir]][l3j[dir]] == 1) pos.push_back(dir);
    }
    const int inf = (int)2e18 + 5;
    int ans = inf;
    rep(i,0,4) {
        int cur = 0;
        rep(j,0,4) {
            cur += min(abs(pos[j] - i), 4 - abs(pos[j] - i));
        }
        ans = min(ans, cur);
    }

    cout << ans << '\n';
}

int32_t main() {
    send help

    int tt = 1;
    if (TC) cin >> tt;
    while (tt--) solve();
}

