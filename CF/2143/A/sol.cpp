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
    vi a(n);
    for (auto &x: a) {
        cin >> x;
    }

    int ind = n-1;
    rep(i,0,n-1) {
        if (a[i] > a[i+1]) {
            ind = i;
            break;
        }
    }

    bool ok = true;
    rep(i,ind,n-1) {
        if (a[i] < a[i+1]) {
            ok = false;
            break;
        }
    }

    cout << (ok ? "YES":"NO") << '\n';
}

