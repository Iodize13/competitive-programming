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

int32_t main() {
    send help

    solve();
}

void solve() {
    string s;
    cin >> s;
    int n = sz(s);
    map<string, bool> mp;
    rep(i,1,7) {
        rep(j,0,n-i+1) {
            mp[s.substr(j,i)] = 1;
        }
    }

    queue<string> que;
    rep(i,1,10) que.push(to_string(i));
    while(!que.empty()) {
        auto cur = que.front();
        que.pop();
        if (!mp[cur]) {
            cout << cur << '\n';
            return;
        }
        rep(i,0,10) que.push(cur + to_string(i));
    }
}

