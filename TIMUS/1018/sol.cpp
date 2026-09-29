// #pragma GCC optimize("O3,unroll-loops")
#include "bits/stdc++.h"

using namespace std;

#define int long long
#define sz(x) (int)(x).size()



void solve() {
	int N, Q; cin >> N >> Q;
	vector<vector<pair<int, int> > > G(N);
	int sum = 0;
	for (int i = 0; i < N - 1; i++) {
		int u, v, cost; cin >> u >> v >> cost;
		--u, --v;
		G[u].push_back({v, cost});
		G[v].push_back({u, cost});
		sum += cost;
	}
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	// vector<pair<int, int> > st(N + 1);
	stack<int> st;
	vector<bool> vis(N);
	vector<int> par(N);
	vector<int> child(N);
	vector<int> A(N);
	int top = 0;
	// st[top] = {0, 0};
	st.push(0);
	par[0] = -1;
	while (!st.empty()) {
		auto node=  st.top();
		st.pop();
		if (vis[node]) continue;
		vis[node] = true;
		for (auto &x: G[node]) {
			if (vis[x.first]) continue;
			par[x.first] = node;
			A[x.first] = x.second;
			st.push(x.first);
		}
	}
	// while (top >= 0) {
	// 	auto &[node, act] = st[top];
	// 	// cerr << "top, node, act: " << top << ' ' << node + 1 << ' ' << act << '\n';
	// 	if (act == sz(G[node])) {
	// 		--top;
	// 		continue;
	// 	}
	// 	if (G[node][act].first != par[node]) {
	// 		par[G[node][act].first] = node;
	// 		A[G[node][act].first] = G[node][act].second;
	// 		st[++top] = {G[node][act].first, 0};
	// 	}
	// 	act++;
	// }
// 	for (int i = 0; i < N; i++)
// 		cerr << "par, A: " << par[i] + 1 << "->" << i + 1 << ' ' << A[i] << '\n';
	for (int i = 0; i < N; i++) {
		child[i] = sz(G[i]);
		if (child[i] == 1 && i != 0) {
			pq.push({G[i][0].second, i});
		}
	}
	while (!pq.empty() && Q) {
		auto [cost, node] = pq.top();
		pq.pop();
		child[par[node]]--;
		if (!child[par[node]] && par[node] != 0)
			pq.push({A[par[node]], par[node]});
		sum -= cost;
		Q--;
	}
	cout << sum << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

    solve();
}

