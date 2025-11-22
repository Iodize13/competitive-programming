// #pragma GCC optimize("O3,unroll-loops")
#include "bits/stdc++.h"

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define dbg(...) 42
#endif
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
#define fi first
#define se second
#define int long long
#define ll long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef vector<int> vi;
typedef pair<int, int> pii;
void solve();
const int di[4] = {0, 0, -1, 1};
const int dj[4] = {-1, 1, 0, 0};
void init();
map<pair<int, int>, string> mp;

int32_t main() {
    send help

    init();
    int tt;
    cin >> tt;
    while (tt--) solve();
}

void solve() {
    int s0, s1;
    cin >> s0 >> s1;
    cout << (mp.count(make_pair(s0, s1)) ? mp[make_pair(s0, s1)] : "No solution") << '\n';
}

void init() {
    queue<pair<string, int> > que;
    for (int i = 1; i < 10; i++) {
        que.push(to_string(i));
    }

    while(!que.empty()) {
        auto [cur, cost] = que.front();
        que.pop();
        // dbg(cur);
        if (sz(cur) ||  >= 100) continue;
        rep(i, cur[sz(cur) - 1] - '0',10) {
            que.push({cur + to_string(i), cost + i});
        }
    }
}
