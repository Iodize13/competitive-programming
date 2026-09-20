// #pragma GCC optimize("O3,unroll-loops")
#include "bits/stdc++.h"

using namespace std;

#define int long long
#define sz(x) (int)(x).size()



void solve() {
	int N, Q; cin >> N >> Q;
	vector<vector<int> > G(N);
	for (int i = 0; i < N - 1; i++) {
		int u, v; cin >> u >> v;
		--u;
		--v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	vector<vector<int> > qs(N);
	vector<int> qd(Q);
	for (int i = 0; i < Q; i++) {
		int v, d; cin >> v >> d;
		--v;
		qs[v].push_back(i);
		qd[i] = d;
	}
	vector<bool> vis(N, false);
	stack<pair<int, int> > st;
	int S, mx;
	vector<int> path(N + 1);
	vector<int> ans(Q);
	auto dfs = [&]() {
		mx = 0;
		st.push({0, S});
		vis.assign(N, false);
		while (!st.empty()) {
			auto [cdist, node] = st.top();
			st.pop();
			if (vis[node]) continue;
			path[cdist] = node;
			if (cdist > mx) {
				mx = cdist;
				S = node;
			}
			for (auto id: qs[node]) {
				if (qd[id] <= cdist)
					ans[id] = path[cdist - qd[id]] + 1;
			}
			vis[node] = true;
			for (auto y:G[node]) {
				if (vis[y]) continue;
				st.push({cdist + 1, y});
			}
		}
	};
	S = 0;
	dfs();
	dfs();
	dfs();
	for (int i = 0; i < Q; i++) {
		cout << ans[i] << '\n';
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

    solve();
}

