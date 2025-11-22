#include<bits/stdc++.h>
#define int long long int

using ll = long long;

using namespace std;

void runcase() {
    string l, r;
    cin >> l >> r;
    int dp[l.size() + 2];
    memset(dp, 0, sizeof dp);
    bool ok = false;
    bool okT = false;
    for (int i = 1; i < l.size() + 1; i++) {
        dp[i] = INT_MAX;
        if (okT) {
            if (ok) {
                for (int j = 0 ; j <= 9; j++) {
                    int cur = ((l[i - 1] - '0') == j) + ((r[i - 1] - '0') == j);
                    // cerr << "cur: " << cur << '\n';
                    dp[i] = min(dp[i], dp[i - 1] + cur);
                }
            } else {
                cerr << "i: " << i << '\n';
                for (int j = l[i - 1] - '0' ; j <= 9; j++) {
                    int cur = ((l[i - 1] - '0') == j) + ((r[i - 1] - '0') == j);
                    // cerr << "cur: " << cur << '\n';
                    dp[i] = min(dp[i], dp[i - 1] + cur);
                }
                for (int j = 0 ; j <= r[i - 1] - '0'; j++) {
                    int cur = ((l[i - 1] - '0') == j) + ((r[i - 1] - '0') == j);
                    // cerr << "cur: " << cur << '\n';
                    dp[i] = min(dp[i], dp[i - 1] + cur);
                }
            }
        } else {
            for (int j = l[i - 1] - '0'; j <= r[i - 1] - '0'; j++) {
                int cur = ((l[i - 1] - '0') == j) + ((r[i - 1] - '0') == j);
                dp[i] = min(dp[i], dp[i - 1] + cur);
            }
        }
        if (r[i - 1] - l[i - 1] >= 2 || (okT && ((r[i - 1] + 10) - (l[i - 1]) >= 2))) {
            cerr << "i: " << i << ", " << r[i - 1] << ", " << l[i - 1] << '\n';
            ok = true;
        }
        if (r[i - 1] != l[i - 1]) okT = true;
        // for (auto X: dp) cerr << X << ' ';
        cerr << '\n';
    }
    // cerr << dp[0] << '\n';
    cout << dp[l.size()] << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--) {
        runcase();
    }
    return 0;
}
