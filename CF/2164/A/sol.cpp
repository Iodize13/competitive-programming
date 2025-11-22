// #pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>

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



const bool TC = 1;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }

    int y; cin >> y;

    cout <<  ((y >= *min_element(all(a)) && y <= *max_element(all(a))) ? "YES": "NO") << '\n';
}

int32_t main() {
    send help

    int tt = 1;
    if (TC) cin >> tt;
    while (tt--) solve();
}
