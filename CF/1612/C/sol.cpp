#include<bits/stdc++.h>
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

int tt = 1;

int n, m, k;
string s;

void sol() {
    cin >> n >> k;

    auto f = [&](int mid) {
        if (mid > n) {
            int r = 2 * n - 1 - mid;
            // cerr << "r: " << r << '\n';
            return ((1 + (2 * n - 1)) * n) / 2 - ((1 + r) * r) / 2;
        } else {
            return ((1 + mid) * mid) / 2;
        }
    };

    int hi = 2* n, lo = 0;
    while(hi - lo > 1) {
        int mid = midpoint(lo, hi);
        if (f(mid) < k) {
            lo = mid;
        } else {
            hi = mid;
        }
    }

    cout << min(lo + 1, 2 *n - 1) << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int testcase(1);
    cin >> testcase;
    while(testcase--) {
        sol();
        tt++;
    }
    return 0;
}

