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

    map<int, int> mp;
    for (int i = sz(a) - 1; i >= 0; i--) {
        mp[a[i]] = 1;
        if (mp.count(a[i] + 1)) mp[a[i]] += mp[a[i] + 1];
    }

    int mx = 1;
    int idx = 0;
    for (auto &[key, val]: mp) {
        if (val >= mx) {
            mx = val;
            idx = key;
        }
    }

    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (a[i] == idx) {
            ans.push_back(i);
            idx++;
        }
    }

    cout << sz(ans) << '\n';
    for (auto &x: ans) cout << x + 1 << ' ';
    cout << '\n';
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

