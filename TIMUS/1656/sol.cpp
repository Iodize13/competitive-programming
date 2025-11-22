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
    vi a(n*n);
    for (auto &x: a) {
        cin >> x;
    }

    auto valid = [&](int r, int c) {
        return r >= 0 && r < n && c >= 0 && c < n;
    };

    sort(all(a));
    int k = n*n - 1;
    vector<vi> g(n, vi(n));
    vector<vector<bool> > vis(n, vector<bool>(n));
    queue<pair<int, int> > que;
    que.push({n / 2, n / 2});
    while(!que.empty()) {
        auto [r, c] = que.front();
        que.pop();
        if (vis[r][c]) continue;
        g[r][c] = a[k--];
        vis[r][c] = 1;
        rep(p,0,4) {
            int nr = r + di[p];
            int nc = c + dj[p];
            if (!valid(nr, nc) || vis[nr][nc]) continue;
            que.push({nr, nc});
        }
    }

    rep(i,0,n) {
        rep(j,0,n) cout << g[i][j] << " \n"[j+1==n];
    }
}

