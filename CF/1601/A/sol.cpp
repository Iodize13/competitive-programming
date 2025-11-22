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
        cin >> n;
        vector<int> a(n);
        for (auto &x: a)
            cin >> x;

        const int K = 30;
        vector<int> bit(K);
        for (auto &x: a) {
            for (int i = 0; i < K; i++) {
                bit[i] += ((1 << i) & x ? 1 : 0);
            }
        }

        int g = 0;
        // cerr << "dbg: \n";
        for (auto &x: bit) {
            g = gcd(g, x);
            // cerr << x << ' ';
        }
        // cerr << '\n';

        // cerr << "g: " << g << '\n';
        set<int> ans;
        for (int i = 1; i <= n; i++) {
            if (g % i == 0) {
                ans.insert(i);
                // ans.insert(g / i);
            }
        }

        for (auto &x: ans) cout << x << ' ';
        cout << '\n';
    };

    while(testcase--) {
        sol();
        tt++;
    }
    return 0;
}

