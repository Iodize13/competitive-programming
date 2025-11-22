#include<bits/stdc++.h>
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < (b); ++i)

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

        const int K = 20;
        vector<vector<int>> bit(20, vector<int>(n));
        for (int i = 0; i <K ; i++) {
            for (int j = 0; j < n; j++) {
                bit[i][j] = !!((1 << i) & a[j]);
            }
        }

        int mx = 1;
        for (int i = 0; i < K; i++) {
            auto it = find(all(bit[i]), 1);
            if (it == bit[i].end()) continue;

            int cur = it - bit[i].begin() + 1;
            int last = cur;
            // cerr << "l: ";
            // cerr << (1 << i) << '\n';
            for (int j = cur, l = 2; j < n; j++, l++) {
                if (bit[i][j]) {
                    l = 1;
                    last = j;
                }
                // cerr << "[" << j << ", " << l << "], ";
                cur = max(cur, l);
            }
            // cerr << '\n';
            cur = max(cur, n - last);
            mx = max(mx, cur);
        }

        cout << mx << '\n';
    };

    while(testcase--) {
        sol();
        tt++;
    }
    return 0;
}

