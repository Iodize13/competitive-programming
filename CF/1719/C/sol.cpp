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
    int q;
    cin >> n >> q;    

    vector<int> a(n);
    deque<int> qu;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        qu.push_back(i);
    }

    int win_round = 0;
    vector<vector<int> > score(n);
    while (a[qu.front()] != n) {
        int f = qu.front();
        qu.pop_front();
        int s = qu.front();
        qu.pop_front();
        if (a[f] > a[s]) {
            qu.push_front(f);
            score[f].push_back(win_round);
            qu.push_back(s);
        } else {
            qu.push_front(s);
            score[s].push_back(win_round);
            qu.push_back(f);
        }
        win_round++;
    }

    // cerr << "win_round: " << win_round << '\n';
    
    for (int i = 0; i < q; i++) {
        int ans = 0;
        int y, k;
        cin >> y >> k;
        // k--; // does it all 0 based?
        y--;
        // cerr << "k: " << k << '\n';
        if (a[y] == n && k >= win_round) {
            ans += max(0LL, k - win_round);
            // cerr << "ans: " << ans << '\n';
            ans += sz(score[y]);
            // cerr << "wtf: " << sz(score[y]) << '\n';
            cout << ans << '\n';
            continue;
        }
        if (k >= win_round) {
            cout << sz(score[y]) << '\n';
            continue;
        }
        k--;
        auto it = upper_bound(all(score[y]), k);
        ans = it - score[y].begin();
        cout << ans << '\n';
    }
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

