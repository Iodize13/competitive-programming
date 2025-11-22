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
    int n, k;
    cin >> n >> k;
    vi a(n), b(k);
    for (auto &x: a) {
        cin >> x;
    }

    int sum = 0;
    for (auto &x: b) {
        cin >> x;
    }
    sort(a.rbegin(), a.rend());
    sort(all(b));
    int j = 0;
    for (int i = 0; i < k; i++) {
        if (n < j + b[i]) break;

        rep(l,0,b[i]-1) {
            sum += a[j];
            j++;
        }
        j++;
    }

    dbg(j);
    rep(i,j,n) sum += a[i];

    cout << sum << '\n';
}

