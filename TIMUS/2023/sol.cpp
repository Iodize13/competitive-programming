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
    auto check = [&](char x) {
        int ret = 0;
        if (x=='A' || x == 'P' || x == 'O' || x == 'R') {
            ret = 0;
        } else if (x=='B'||x=='M'||x=='S') {
            ret = 1;
        } else ret = 2;
        return ret;
    };

    vector<string> a(n);
    for (auto &x: a) {
        cin >> x;
    }
    int ans = check(a[0][0]);
    rep(i,0,n-1) {
        ans += abs(check(a[i][0]) - check(a[i+1][0]));
    }

    cout << ans << '\n';
}

