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
    cin >> n >> m;
    vector<int> a(m);
    vector<int> freq(n);
    for (auto &x: a) {
        cin >> x;
        x--;
        freq[x]++;
    }

    int mn = 0;
    // for (int i = 0; i < n; i++) {
    //     mn = min(mn, freq[i]);
    // }

    // for (int i = 0; i < n; i++) {
    //     freq[i] -= mn;
    // }

    // cerr << "mn: " << mn << '\n';

    auto check = [&](int h) {
        int sub = 0;
        int add = 0;
        for (int i = 0; i < n; i++) {
            sub += max(0LL, freq[i] - h);
            add += max(0LL, (h - freq[i]) / 2);
        }
        
        // cerr << sub << ' ' << add << '\n';

        return sub <= add;
    };
    
    int hi = 2 * m, lo = 0;
    while (hi - lo > 1) {
        int mid = midpoint(lo, hi);
        if (check(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }

    // cerr << "lo: " << hi << '\n';
    mn += hi;
    cout << mn << '\n';
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

