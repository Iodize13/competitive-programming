#include<bits/stdc++.h>
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

int tt = 1;

int n, m, k;
string s;

void sol() {
    cin >> n;
    int cntA = 0;
    for (int i = 0; i < n; i++) {
        int H;
        cin >> H;
        cntA += (H % 2 == 1);
    }

    int dp[n + 1][n + 1];
    memset(dp, 0, sizeof dp);
    dp[1][0] = 1;
    dp[1][1] = 0;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            dp[i][j] |= dp[i - 1][j];
        }
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            cerr << dp[i][j];
        }
        cerr << '\n';
    }
    cout << (dp[n][cntA] ? "Alice" : "Bob") << '\n';
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

