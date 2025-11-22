#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <deque>
#include <stack>
#include <cstdint>
#include <bitset>
#include <cstring>
#include <cmath>
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < (b); ++i)

using namespace std;
int n, m, k;

void sol() {
    cin >> n;
    vector<int> cost;
    vector<int> weight;
    for (long long i = 0, f = 1LL; i < n && f <= n; i++, f *= 3LL) {
        cerr << f << '\n';
        cost.push_back(f);
        weight.push_back(f * 3LL + i * (f / 3LL));
    }

    // const int INF = 1e18 + 5;
    // vector<int> dp(n + 1, INF);
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 0; j < sz(cost); j++) {
    //         if (i - cost[j] >= 0) dp[i] = min(dp[i], dp[i - cost[j]] + 1);
    //     }
    // }

    cerr << dp[n] << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt = 1, testcase(1);
    string s;
    cin >> testcase;

    while(testcase--) {
        sol();
        tt++;
    }
    return 0;
}

