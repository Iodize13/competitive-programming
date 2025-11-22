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

    int sum = accumulate(all(a), 0LL);
    sort(all(a));
    cin >> m;
    vector<pair<int, int> > b(m);
    for (auto &[f, s]: b)
        cin >> f >> s;

    for (auto &[x, y]: b) {
        int ans = INT64_MAX;
        if (x >= sum - y) {
            auto it = lower_bound(all(a), sum - y);
            if (it != a.end() && *it <= x) ans = x + y - sum;
        }
        //cerr << "ans: " << ans << '\n';
        auto itx = lower_bound(all(a), x);
        auto ity = upper_bound(all(a), sum - y);
        if (ity != a.begin()) {
            //cerr << "ity: " << *prev(ity) << '\n';
            ans = min(ans, max(0LL, x - *prev(ity)));
        }
        //cerr << "ans: " << ans << '\n';
        if (itx != a.end()) ans = min(ans, max(0LL, y - sum + *itx));
        //cerr << "ans: " << ans << '\n';

        cout << ans << '\n';
    }
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

