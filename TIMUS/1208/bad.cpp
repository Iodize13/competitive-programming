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
    int n;
    cin >> n;
    vector<array<string, 3> > a(n);
    rep(i,0,n) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }


    int ans = 0;
    auto check = [&](int x) {
        map<string, bool> mp;
        bool good = true;
        rep(i,0,n) {
            if ((1<<i) & x) {
                rep(j,0,3) {
                    if (mp.count(a[i][j])) {
                        good = false;
                        break;
                    }
                    mp[a[i][j]] = true;
                }
            }
            if (!good) break;
        }
        if (good) ans = max(ans, (int)__builtin_popcountl(x));
    };

    rep(i,0,(1<<n)) {
        check(i);
    }

    cout << ans << '\n';
}

int32_t main() {
    send help

    int tt = 1;
    if (TC) cin >> tt;
    while (tt--) solve();
}

