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
    bool ok = true;
    bool fail = false;
    int sum = 0;
    rep(i,0,n) {
        int x;
        cin >> x;
        sum += x;
        if (x != 5) ok = false;
        if (x == 3) fail = true;
    }

    if (ok) {
        cout << "Named\n";
        return;
    }

    if (fail) {
        cout << "None\n";
        return;
    }

    if (sum *2 >= 9 * n) {
        cout << "High\n";
        return;
    }

    cout << "Common\n";
}

