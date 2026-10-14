// #pragma GCC optimize("O3,unroll-loops")
#include "bits/stdc++.h"

using namespace std;

#define int long long
#define sz(x) (int)(x).size()



struct node {
	vector<pair<int,int> > child;
};

void solve() {
	int N, Q; cin >> N >> Q;
	vector<vector<pair<int, int> > > G(N);
	for (int i = 0; i < N - 1; i++) {
		int u, v, cost; cin >> u >> v >> cost;
		--u, --v;
		G[u].push_back({v, cost});
		G[v].push_back({u, cost});
	}
	const int inf = (int)1e9;
	vector<array<int, 2> > st(N + 1);
	vector<int> vis(N, false);
	vector<vector<int> > depth;
	vector<node> tree(N);
	vector<vector<int> > dp(N, vector<int>(Q + 1, 0));
	int top = 0;
	st[top] = {0,0};
	while (top >= 0) {
		auto [node, cdepth] = st[top];
		// cerr << "top, st[top]: " << top << ", " << st[top][0] << ", " << st[top][1] << '\n';
		if (vis[st[top][0]]) {
			--top;
			continue;
		}
		vis[st[top][0]] = true;
		if (st[top][1] >= sz(depth)) {
			depth.push_back({});
		}
		depth[st[top][1]].push_back(st[top][0]);
		for (auto &y: G[node]) {
			if (vis[y.first]) continue;
			st[++top] = {y.first, cdepth + 1};
			tree[node].child.push_back(y);
			// dp[y.first][0] = y.second;
		}
	}
	// for (int i = 0; i < sz(depth); i++) {
	// 	for (int j = 0; j < sz(depth[i]); j++) {
	// 		cerr << depth[i][j] << ' ';
	// 	}
	// 	cerr << '\n';
	// }
	for (int i = 0; i < N; i++)
		dp[i][0] = 0;
	for (int i = sz(depth) - 1; i >= 0; i--) {
		for (int j = 0; j < sz(depth[i]); j++) {
			auto u = depth[i][j];
			if (tree[u].child.empty()) {
				// cerr << "case: 5" << endl;
				// cerr << "i: " << i << '\n';
				continue;
			}
			for (int k = 1; k <= Q; k++) {
				// cerr << "case: 6" << endl;
				auto c = tree[u].child;
				for (int m = 1; m <= k + 1; m++) {
					// cerr << "i, j, u, k, m: " << i << ' ' << j << ' ' << u << ' ' << k << ' ' << m << '\n';
					// cerr << "c[1]: " << c[1].first << '\n';
					
					int cur = 0;
					if (m - 2 >= 0)
						cur += dp[c[1].first][m - 2];
					if (k - m >= 0)
						cur += dp[c[0].first][k - m];
					// cerr << "dp[c[0].first][m]: " << dp[c[0].first][m] << '\n';
					if (m != k + 1)
						cur += tree[u].child[0].second;
					if (m != 1)
						cur += tree[u].child[1].second;
					dp[u][k] = max(dp[u][k], cur);
					// cerr << "dp[u][k]: " << dp[u][k] << '\n';
				}
			}
		}
	}
	// for (int i = 0; i < N; i++) {
	// 	for (int j = 0; j <= Q; j++) {
	// 		cerr << dp[i][j] << " \n"[j == Q];
	// 	}
	// }
	cout << dp[0][Q] << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

    // int tt; cin >> tt;
	// while (--tt) 
	solve();
}

// can't just + 2-4 to every dp because last iter shouldn't include it.
