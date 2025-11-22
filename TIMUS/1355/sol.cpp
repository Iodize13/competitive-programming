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
    int a, b;
    cin >> a >> b;
    if (b % a != 0) {
        cout << 0 << '\n';
        return;
    }

    int n = b / a;
    int ans = 1;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            ans++;
            n /= i;
        }
    }

    if (n > 1) ans++;

    cout << ans << '\n';
}

int32_t main() {
    send help

    int tt = 1;
    if (TC) cin >> tt;
    while (tt--) solve();
}

