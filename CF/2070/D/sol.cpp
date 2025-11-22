#include<bits/stdc++.h>
#define int long long int

using namespace std;

const int MOD = 998244353;

void runcase() {
    int n;
    cin >> n;
    vector<int> D(n);
    vector<int> v(n);
    v[0] = -1;
    D[0] = 0;
    vector<vector<int>> adj(n);
    vector<vector<int>> child(n);
    adj[0].push_back(0);
    int dp[n];
    int dpC[n];
    memset(dp, 0, sizeof dp);
    memset(dpC, 0, sizeof dpC);
    for (int i = 1; i < n; i++) {
        int par;
        cin >> par;
        --par;
        v[i] = par;
        dp[par] = 0;
        dp[i] = 1;
        D[i] = D[par] + 1;
        adj[D[i]].push_back(i);
        child[par].push_back(i);
    }
//     for (auto X: child) {
//         for (auto Y: X) {
//             cerr << Y + 1 << ' ';
//         }
//         cerr << '\n';
//     }
//     for (auto X: dp) cerr << X << ' ';
//     cerr << '\n';

//     for (auto X: D) cerr << X << ' ';
//     cerr << '\n';

//    for (auto X: v) cerr << X << ' ';
//    cerr << '\n';
//     stack<tuple<int,int, int>> st;
//     st.push(0, -1, 1);
//     vector<int> vis(n);
    int mx = *max_element(D.begin(), D.end()) ;
//     while(!st.empty()) {
//         auto [cur, par, ret] = st.top();
//         st.pop();
//         vis[cur] = ret;
//         if (D[cur] = *max_element(D.begin(), D.end())) {
//             // 
//             continue;
//         }
//         for (auto X: adj[D[cur] + 1]) {
//             if (vis[X]) {
//                 
//                 continue;
//             }
//             if (v[X] == cur) continue;
//             st.push(X, cur);
//         }
//         // + 1;
//     }
    vector<int> sum(mx + 2);
    sum[mx] = adj[mx].size();
    cerr << "dbg: ";
    // for (auto X: sum) cerr << X << ' ';
    cerr << '\n';
    // cerr << sum[mx] << '\n';
    for (auto node: adj[mx]) {
        cerr << "node: " << node + 1 << '\n';
        dp[node] = 1;
        // cerr << "tmp: " << tmp << '\n';
        dpC[v[node]] = (dpC[v[node]] + dp[node]) % MOD;
    }
    for (int j = mx - 1; j >= 0; j--) {
        for (auto node: adj[j]) {
            cerr << "node: " << node + 1 << '\n';
            dp[node] = 1;
            // cerr << "tmp: " << tmp << '\n';
            if (j != 0) {
                dp[node] = ((dp[node] + sum[j + 1]) % MOD - dpC[node]) % MOD;
                dp[node] += (dp[node] < 0) * MOD;
            }
            else  dp[node] = (dp[node] + sum[j + 1]) % MOD;
            sum[j] = (sum[j] + dp[node]) % MOD;
            cerr << "sum: " << sum[j] << '\n';
            if (j != 0) dpC[v[node]] = (dpC[v[node]] + dp[node]) % MOD;
        }
    }

    cout << dp[0] << '\n';
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
