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

void sol();

int case_num = 0;

int32_t main() {
    send help

    int tt;
    cin >> tt;
    while(tt--) {
        ++case_num;
        sol();
    }
}

void sol() {
    int n, m;
    cin >> n >> m;
    vi a(n), b(n);
    rep(i,0,n) {
        cin >> a[i] >> b[i];
    }
    
    int pos = 0;
    int to = 0;
    int ans = 0;
    rep(i,0,n) {
        ans += a[i] - pos - ((a[i] - pos - to) % 2 != b[i]);
        // cerr << "to: " << to << '\n';
        // cerr << "a[i]: " <<  a[i] << ", pos: " << pos << '\n';
        // cerr << "i: " << i << ", ans: " << ans << '\n';
        pos = a[i];
        to = b[i];
    }
    ans += m - pos;
    cout << ans << '\n';
}

