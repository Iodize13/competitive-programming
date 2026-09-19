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
	map<int, vector<int> > mp;
	map<int, vector<pair<int, int> > > want;
	vector<pair<int, int> > qr;
	for (int i = 0; i < Q; i++) {
		int v, d; cin >> v >> d;
		--v;
		qr.push_back({v, d});
		mp[v].push_back(d);
	}
	vector<bool> vis(N, false);
	stack<pair<int, int> > st;
	st.push({0,0});
	int S = 0, mx = 0;
	while (!st.empty()) {
		auto [cdist, node] = st.top();
		st.pop();
		if (vis[node]) continue;
		if (cdist > mx) {
			// cerr << "mx: " << cdist << ' ' << node << '\n';
			mx = cdist;
			S = node;
		}
		// cerr << "cdist, node: " << cdist << ' ' << node << '\n';
		vis[node] = true;
		for (auto y:G[node]) {
			st.push({cdist + 1, y});
		}
	}
	map<pair<int,int>, int> res;
	auto dfs = [&]() {
		mx = 0;
		// cerr << "S: " << S << '\n';
		st.push({0, S});
		vis.assign(N, false);
		map<int,int> fb;
		while (!st.empty()) {
			auto [cdist, node] = st.top();
			st.pop();
			if (vis[node]) continue;
			fb[cdist] = node;
			if (cdist > mx) {
				mx = cdist;
				S = node;
			}
			// for (auto y: want[cdist]) {
			// 	res[make_pair(y.first, cdist - y.second)] = node;
			// }
			// if (node == 0) {
			// 	cerr << "0: " << cdist << '\n';
			// }
			for (auto need: mp[node]) {
				// if ()
				// doesn't need to handle over need + cdist > N
				// want[need + cdist].push_back({node, cdist});
				// if (node == 7) {
				// 	cerr << "7: " << cdist << ' ' << need << '\n';
				// }
				if (fb.count(cdist - need)) {
					res[make_pair(node, need)] = fb[cdist - need];
				}
			}
			vis[node] = true;
			for (auto y:G[node]) {
				if (vis[y]) continue;
				st.push({cdist + 1, y});
			}
		}
	};
	dfs();
	// for (int i = 0; i < Q; i++) {
	// 	cerr << "qr[i]: " << qr[i].first << ' ' << qr[i].second << '\n';
	// 	cerr << (res.count(qr[i]) ? res[qr[i]] + 1 : 0) << '\n';
	// }
	dfs();
	// cerr << "second round\n=============\n";
	for (int i = 0; i < Q; i++) {
		cout << (res.count(qr[i]) ? res[qr[i]] + 1 : 0) << '\n';
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

    solve();
}

