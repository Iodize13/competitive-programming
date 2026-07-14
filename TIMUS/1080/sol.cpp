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
const int inf = (int)2e18 + 5;

int32_t main() {
    send help

	solve();
}

void solve() {
    int N; cin >> N;
    vector<vector<int> > G(N);
    for (int i = 0; i < N; i++) {
	int x;
	while(cin >> x) {
	    if (x == 0) break;
	    --x;
	    G[i].push_back(x);
	    G[x].push_back(i);
	}
    }
    vector<int> ans(N, 2);
    stack<pair<int, int> > st;
    for (int i = 0; i < N; i++) {
	if (ans[i] != 2) continue;
	st.push({i, 0});
	while(!st.empty()) {
	    auto [cNode, col] = st.top();
	    st.pop();
	    if (ans[cNode] != 2) {
	    	if (ans[cNode] != col) {
			cout << "-1\n";
			return;
		}
		continue;
	    }
	    ans[cNode] = col;
	    for (auto &next: G[cNode]) {
		st.push({next, !col});
	    }
	}
    }
    for (auto &x: ans) cout << x;
    cout << '\n';
}

