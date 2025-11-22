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
int case_num = 0;
const int di[4] = {0, 0, -1, 1};
const int dj[4] = {-1, 1, 0, 0};

int32_t main() {
    send help

    int tt;
    cin >> tt;
    while(tt--) {
        ++case_num;
        solve();
    }
}

void solve() {
    string s;
    int n;
    cin >> n;
    vi a(n+1);
    vi f(n + 2);
    rep(i,1,n+1) {
        cin >> a[i];
        f[a[i]]++;
    }

    int mex = 1;
    while (f[mex]) {
        mex++;
        // dbg(mex);
    }
    dbg(mex);

    for (int i = n; i >= 1; i--) {
        if (a[i] == 0) a[i] = mex++;
    }

    int ans = 0;
    vi p(n + 1);
    rep(i,1,n+1) {
        dbg(a[i]);
        p[a[i]] = i;
    }

    // rep(i,1,n+1) {
    //     cerr << a[i] << ' ';
    // }
    // cerr << '\n';

    vector<bool> vis(n+1);
    rep(i,1,n+1) {
        if (a[i] != i && !vis[i]) {
            int mx = a[i];
            int cur = i;
            do {
                vis[cur] = 1;
                cur = a[cur];
                dbg(cur);
                mx = max(mx, cur);
            } while (a[cur] != i);
            ans = max(mx - i + 1, ans);
        }
    }
    cout << ans << '\n';
}
