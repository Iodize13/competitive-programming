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
    int x, y;
    cin >> n >> x >> y;    

    string s, t;
    cin >> s >> t;
    vector<int> d;
    for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) d.push_back(i);
    }

    if (sz(d) % 2 == 1) {
        cout << "-1\n";
        return;
    }

    if (sz(d) == 2 && d[1] - d[0] == 1) {
        cout << min(2 * y, x) << '\n';
        return;
    }

    cout << y * sz(d) / 2 << '\n';
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

