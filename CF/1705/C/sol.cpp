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
int n, m;

void sol() {
    int c, q;
    cin >> n >> c >> q;
    string s;
    cin >> s;
    vector<pair<int, int> > from;
    int length = n;
    rep(i, 0, c) {
        int st, en;
        cin >> st >> en;
        st--;
        en--;
        from.push_back({length, st});
        length += en - st + 1;
    }

    const int INF = (int)1e18 + 5;

    rep(i,0,q) {
        int k;
        cin >> k;
        k--;

        auto it = upper_bound(all(from), make_pair(k, INF));
        while (it != from.begin()) {
            auto last = *prev(it);
            k -= last.first - last.second;
            // cerr << "last.first: " << last.first << '\n';
            // cerr << "last.second: " << last.second << '\n';
            // cerr << "k: " << k << '\n';
            it = upper_bound(all(from), make_pair(k, INF));
        }
        cout << s[k] << '\n';
        continue;
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt = 1, testcase(1);
    string s;
    cin >> testcase;

    while(testcase--) {
        // cerr << "tt: " << tt << '\n';
        sol();
        tt++;
    }
    return 0;
}

