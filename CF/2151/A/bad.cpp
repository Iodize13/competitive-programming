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



const bool TC = 1;
void solve() {
    int n, m;
    cin >> n >> m;
    vi b(m);
    for (auto &x: b) {
        cin >> x;
    }

    auto it = max_element(all(b)) - b.begin();
    if (b[it] > n) {
        cout << 0 << '\n';
        return;
    }

    // handle case 1 1
    int mx = b[0];
    bool first = true;
    for (int i = 0 ; i < m-1; i++) {
        mx = b[i];
        if (b[i] >= b[i+1]) break;
    }
    for (int i = 0; i < m-1; i++) {
        if (b[i] >= b[i+1]) {
            if (!first && b[i] != mx + 1) {
                // cerr << "i: " << i << ", mx: " << mx << '\n';
                cout << 0 << '\n';
                return;
            }
            first = false;
            mx = b[i];
        } else {
            if (b[i + 1] - b[i] != 1) {
                // cerr << "case 2: " << ", i: " << i << '\n';
                cout << 0 << '\n';
                return;
            }
        }
    }

    if (first) {
        cout << n - b[m - 1] + 1 << '\n';
        return;
    }

    cout << 1 << '\n';
    // need to handle 3 1 // m == n but has trail.
}

int32_t main() {
    send help

    int tt = 1;
    if (TC) cin >> tt;
    while (tt--) solve();
}

