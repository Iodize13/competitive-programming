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
#include <cstring>
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < (b); ++i)

using namespace std;
int n, m, k;

const int N = 100'001;

void sol() {
    cin >> n;
    vector<int> a(n);
    for (auto &x: a)
        cin >> x;

    vector<int> freq((int)1e5 + 10);
    vector<int> dp(N + 1);

    for (auto &x: a) freq[x] += x;

    dp[1] = freq[1];
    for (int i = 2; i <= N; i++) {
        dp[i] = max(freq[i] + dp[i - 2], dp[i - 1]);
    }

    int mx = *max_element(all(a));

    cout << dp[mx] << '\n';
    // if (i == 0) return 0;
    // 
    // int ret = f(i - 1, 0);
    // if (!last) max(f(i - 1, 1) + freq[i], ret);
    // return ret;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt = 1, testcase(1);
    string s;

    while(testcase--) {
        sol();
        tt++;
    }
    return 0;
}

