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

int32_t main() {
    send help

    solve();
}

void solve() {
    int n;
    cin >> n;
    vector<vi> g(n, vi(n));
    for (int i = 0, m = 1; i < n; i++) {
        for (int j = 0 ; j < i+1; j++, m++) {
            g[j][i-j] = m;
        }
    }

    rep(i,0,n) reverse(all(g[i]));
    reverse(all(g));
    for (int i = 0, m = n * n; i < n; i++) {
        for (int j = 0 ; j < i+1; j++, m--) {
            g[j][i-j] = m;
        }
    }

    reverse(all(g));
    rep(i,0,n) {
        // reverse(all(g[i]));
        rep(j,0,n) {
            cout << g[i][j] << " \n"[j+1==n];
        }
    }
}

