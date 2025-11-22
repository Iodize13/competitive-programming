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
const int MAX = 1e8 + 1;
bitset<MAX> dp;

int32_t main() {
    send help

    int tt = 1;
    if (TC) cin >> tt;
    while (tt--) {

        int n;
        cin >> n;
        vi a(n);
        for (auto &x: a) {
            cin >> x;
        }

        dp[0] = 1;
        for (int coin = 0; coin < n; coin++) {
            for (int sum = MAX - 1; sum >= 1; sum--) {
                if (sum - a[coin] >= 0) dp[sum] = dp[sum - a[coin]]; // use assign instead
            }
        }

        int mex = 0;
        while (dp[mex]) mex++;
        cout << mex << '\n';
    }
}

// n == 1?
