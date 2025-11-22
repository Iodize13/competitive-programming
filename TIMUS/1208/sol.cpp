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
const int K = 18;
string a[K + 1][3];
void solve() {
    int n;
    cin >> n;
    rep(i,0,n) {
        rep(j,0,3) {
            cin >> a[i][j];
        }
    }

    auto f = [&](auto &&self, int x, bool take, map<string, bool> dp) {
        if (x == 0) return 0ll;
        if (take) {
            rep(j,0,3) {
                dp[a[x][j]] = true;
            }
        }
        int ret = self(self, x - 1, 0, dp);
        bool good = true;
        rep(i,0,3) {
            good &= !dp[a[x-1][i]];
        }
        if (good) ret = max(ret, self(self, x - 1, 1, dp) + 1);
        return ret;
    };
    
    map<string, bool> dp0;
    int f0 = f(f, n-1,0, dp0);
    int f1 = f(f, n-1,1, dp0) + 1;
    cout << max(f0, f1) << '\n';
}

int32_t main() {
    send help

    int tt = 1;
    if (TC) cin >> tt;
    while (tt--) solve();
}
