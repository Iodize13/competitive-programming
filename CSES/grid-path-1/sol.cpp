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

    const int mod = (int)1e9 + 7;

    auto sol = [&]() {
        cin >> n;
        vector<vector<char > > g(n, vector<char> (n));
        rep(i, 0, n) {
            rep(j, 0, n) {
                cin >> g[i][j];
            }
        }

        int dp[(int)1000 + 10][(int)1000 + 10];
        memset(dp, 0, sizeof dp);
        dp[0][0] = 1;
        rep(i,0,n) {
            rep(j,0,n) {
                if (i - 1 >= 0 && g[i - 1][j] != '*') dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
                if (j - 1 >= 0 && g[i][j - 1] != '*') dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;
            }
        }

        cout <<  (g[n - 1][n - 1] == '.' ? dp[n - 1][n - 1] % mod : 0) << '\n';
    };

    while(testcase--) {
        sol();
        tt++;
    }
    return 0;
}

