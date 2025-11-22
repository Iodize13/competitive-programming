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
    int n;
    cin >> n;
    auto ASK = [&](string x) {
        cout << "? " << x << endl;
        int y;
        cin >> y;
        return y;
    };

    string s = "0";
    int x = ASK(s);
    if (x == 0) {
        cout << "! ";
        rep(i,0,n) cout << 1;
        cout << endl;
        return;
    }
    bool back = false;
    auto cur = s;
    while (1) {
        if (sz(cur) == n) {
            cout << "! " << cur << endl;
            return;
        }
        string pa = "01";
        if (!back) {
            bool ok = false;
            for (char bit: pa) {
                int y = ASK(bit + cur);
                if (y) {
                    cur = bit + cur;
                    ok = true;
                    break;
                }
            }
            if (ok) continue;
            back = true;
        }
        for (char bit: pa) {
            int y = ASK(cur + bit);
            if (sz(cur) == n - 1) {
                if (bit == '0' && !y) {
                    cur = cur + '1';
                    break;
                }
            }
            if (y) {
                cur = cur + bit;
                break;
            }
        }
    }
}

