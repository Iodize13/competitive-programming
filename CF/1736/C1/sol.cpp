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
    vector<int> a(n);
    for (auto &x: a)
        cin >> x;

    vector<int> dp(n + 1);
    dp[0] = 0;
    for (int i = 1; i < n + 1; i++) {
        dp[i] = min(dp[i - 1] + 1, a[i - 1]);
    }

    int ans = 0;
    for (int i = 1; i < n + 1; i++) {
        ans += dp[i];
    }

    cout << ans << '\n';
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

