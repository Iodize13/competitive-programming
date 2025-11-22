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
#include <cassert>
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

    vector<int> b(n);
    for (auto &x: b)
        cin >> x;

    vector<int> mn;
    vector<int> mx(n);
    for (auto &x: a) {
        auto it = lower_bound(all(b), x);
        assert(it != b.end());
        mn.push_back(*it - x);
        // mx.push_back(b[n - 1] - x);
    }

    int last = 0;

    for (int i = 0; i < n; i++) {
        // cerr << "last: " << last << '\n';
        if (i >= last) {
            for (int j = i + 1; j < n; j++) {
                if (a[j] > b[j - 1]) break;
                last = j;
            }
        }
        mx[i] = max(b[i] - a[i], b[last] - a[i]);
    }

    for (auto &x: mn) cout << x << ' ';
    cout << '\n';
    for (auto &x: mx) cout << x << ' ';
    cout << '\n';
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

