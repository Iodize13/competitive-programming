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
    int n, m, x0, y0;
    cin >> n >> m >> x0 >> y0;
    vi a(n), b(m);
    for (auto &x: a) {
        cin >> x;
    }

    for (auto &x: b) {
        cin >> x;
    }

    cout << (m + n) << '\n';
}

