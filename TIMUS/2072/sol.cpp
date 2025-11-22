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
    vi a(n);
    map<int, vi> p;
    map<int, array<int, 2> > dp;
    rep(i,0,n) {
        cin >> a[i];
        p[a[i]].push_back(i);
    }

    int ind = 0;
    for (auto &[x, v]: p) {
        int r = 0, l = 1;
        if (x == p.begin()->first) {
            dp[x][r] = 0;
            dp[x][l] = v.back();
            dp[x][r] += v.back();
            dp[x][l] += v.back() - v[0];
            dbg(dp[x][r]);
            dbg(dp[x][l]);
            ind = x;
            continue;
        }
        dp[x][r] = min(dp[ind][r] + abs(v[0] - p[ind].back()),
                dp[ind][l] + abs(v[0] - p[ind][0]));
        dbg(abs(v[0] - p[ind].back()));

        dp[x][l] = min(dp[ind][r] + abs(p[ind].back() - v.back()),
                dp[ind][l] + abs(p[ind][0] - v.back()));
        dbg(abs(p[ind][0] - v.back()));
        dp[x][r] += v.back() - v[0];
        dp[x][l] += v.back() - v[0];
        dbg(dp[x][r]);
        dbg(dp[x][l]);

        ind = x;
    }

    cout << min(dp[ind][0], dp[ind][1]) + n << '\n';
}

