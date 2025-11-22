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
    int to = 0;
    for (auto &x: a) {
        cin >> x;
        to += x;
    }

    if (to % 3 != 0) {
        cout << "0 0\n";
        return;
    }

    rep(_,0,3) {
        int sum = 0;
        int l0 = -1, r0 = -1;
        rep(i,0,n) {
            sum += a[i];
            if (sum % 3 == _) {
                sum = 0;
                if (l0 == -1) l0 = i;
                else if (r0 == -1 && i < n - 1) r0 = i;
            }
        }

        if (l0 != -1 && r0 != -1) {
            cout << l0 + 1 << ' ' << r0 + 1 << '\n';
            return;
        }
    }

    rep(_,0,3) {
        int sum = 0;
        int l0 = -1, r0 = -1;
        rep(i,0,n) {
            sum += a[i];
            if (l0 != -1) {
                int y = (to - (sum % 3 + _)) % 3;
                if (sum % 3 != _ && y != _ && sum % 3 != y) {
                    r0 = i;
                    break;
                }
            }
            if (sum % 3 == _) {
                sum = 0;
                l0 = i;
            }
        }

        if (l0 != -1 && r0 != -1 && r0 != n - 1) {
            dbg("case 1");
            cout << l0 + 1 << ' ' << r0 + 1 << '\n';
            return;
        }
    }
    cout << "0 0\n";
}

