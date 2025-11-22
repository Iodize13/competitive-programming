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
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < (b); ++i)

using namespace std;
int n, m, k;

void sol() {
    cin >> n;
    vector<int> a(n);
    for (auto &x: a)
        cin >> x;

    vector<int> pref0(n + 1);
    vector<int> temp(n);
    vector<int> pref1(n + 1);
    for (int i = 1; i < n - 1; i++) {
        temp[i] = max(0LL, max(a[i -1], a[i + 1]) -a[i] + 1);
    }

    if (n % 2 == 1) {
        int ans = 0;
        for (int i = 1; i < n - 1; i += 2) {
            ans += temp[i];
        }

        cout << ans << '\n';
        return;
    }

    // for (auto &x: temp) cerr << x << ' ';
    // cerr << '\n';

    for (int i = 2; i <= n; i+=2) {
        pref0[i] = pref0[i - 2] + temp[i - 1];
        if (i + 1 <= n) pref0[i + 1] = pref0[i];
    }

    for (int i = 3; i <= n; i+= 2) {
        pref1[i] = pref1[i - 2] + temp[i - 1];
        if (i + 1 <= n) pref1[i + 1] = pref1[i];
    }

    // for (auto &x: pref0) cerr << x<< ' ';
    // cerr << '\n';

    // for (auto &x: pref1) cerr << x<< ' ';
    // cerr << '\n';

    int ans = INT64_MAX;
    for (int i = 0; i < n; i++) {
        ans = min(ans, pref0[i] + pref1[n] - pref1[i]);
    }

    cout << ans << '\n';
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

