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
void init();
map<int, int> dp;

int32_t main() {
    send help

    init();
    int tt;
    cin >> tt;
    while (tt--) solve();
    cout << '\n';
}

void solve() {
    string s;
    int n;
    cin >> n;
    cout << dp[n] << ' ';
}

void init() {
    int j = 0;
    int x = 1;
    dp[x] = 1;
    while (x < (1ll << 32)) {
        x += j;
        dp[x] = 1;
        j++;
    }
}

