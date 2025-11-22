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
    int n, d, k;
    cin >> n >> d >> k;
    vi lp(n), ln(n);
    rep(i,0,k) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        ln[l]++;
        lp[r]++;
    }

    int sum = 0;
    rep(i,0,d) {
        sum += ln[i];
    }

    int mn = sum;
    int mx = sum;
    sum -= lp[0];
    int imn = 0, imx = 0;
    dbg(sum);
    rep(i,1,n-d+1) {
        // back
        sum += ln[i+d-1];
        if (mx < sum) {
            mx = sum;
            imx = i;
        }

        if (mn > sum) {
            mn = sum;
            imn = i;
        }
        // cerr << "i: " << i + 1 << ", sum : " << sum << '\n';
        // front
        sum -= lp[i];
    }

    cout << imx + 1 << ' ' << imn + 1 << '\n';
}

