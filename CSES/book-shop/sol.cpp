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

    auto sol = [&]() {
        cin >> n >> m;
        vector<int> w(n);
        vector<int> c(n);
        for (auto &x: w)
            cin >> x;

        for (auto &x: c)
            cin >> x;

        int dp[(int)1e5 + 10];
        memset(dp, 0, sizeof dp);

        rep(i, 0, n) {
            for (int j = m; j >= 0; j--) {
                if (j - w[i] >= 0) dp[j] = max(dp[j], dp[j - w[i]] + c[i]);
            }
        }

        cout << dp[m] << '\n';
    };

    while(testcase--) {
        sol();
        tt++;
    }
    return 0;
}

