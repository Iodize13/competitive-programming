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
int n, m, k, tt = 1;

void sol() {
    int q;
    cin >> n >> q;    
    vector<int> temp(n);
    iota(all(temp), 0);
    set<int> h(all(temp)), w(all(temp));
    vector<int> cntw(n);
    vector<int> cnth(n);
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int x, y;
            cin >> x >> y;
            --x; --y;
            w.extract(x);
            h.extract(y);
            cntw[x]++;
            cnth[y]++;
        } else if (t == 2) {
            int x, y;
            cin >> x >> y;
            --x; --y;
            cntw[x]--;
            cnth[y]--;
            if (!cntw[x]) w.insert(x);
            if (!cnth[y]) h.insert(y);
        } else {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            // if (tt == 27284) {
            //     string ret = to_string(x1) + "," +
            //     to_string(y1) + "," +
            //     to_string(x2) + "," +
            //     to_string(y2);
            //     cout << ret << '\n';
            // }
            tt++;
            --x1; --y1; --x2; --y2;
            auto iy = h.lower_bound(y1);
            if (iy == h.end() || *iy > y2) { // >=? yes
                cout << "YES\n";
                continue;
            }
            auto ix = w.lower_bound(x1);
            if (ix == w.end() || *ix > x2) { // >=? yes
                cout << "YES\n";
                continue;
            }

            cout << "NO\n";
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int testcase(1);
    string s;

    while(testcase--) {
        sol();
    }
    return 0;
}

