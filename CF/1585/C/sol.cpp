#include<bits/stdc++.h>
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;
int n, m, k;

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt = 1, testcase(1);
    string s;
    cin >> testcase;

    auto sol = [&]() {
        cin >> n >> k;
        vector<int> a(n);
        for (auto &x: a)
            cin >> x;

        auto dist = [&](vector<int> &b) {
            int ret = 0;
            for (int i = 0; i < sz(b); i += k) {
                ret += 2 * b[i];
            }
            return ret;
        };

        sort(all(a));
        auto it = lower_bound(all(a), 0);
        vector<int> neg(a.begin(), it);
        a.erase(a.begin(), it);
        reverse(all(a));
        
        for (auto &x: neg) x *= -1;

        int l = (a.empty() ? 0 : a[0]);
        int r = (neg.empty() ? 0 : neg[0]);
        int ans = dist(a) + dist(neg) - max(l, r);

        cout << ans << '\n';
    };

    while(testcase--) {
        sol();
        tt++;
    }
    return 0;
}

