// #pragma GCC optimize("O3,unroll-loops")
#include "bits/stdc++.h"

using namespace std;

#define int long long
#define sz(x) (int)(x).size()



void solve() {
	int N, M; cin >> N >> M;
	int S, F, R;
	vector<vector<int> > G(M);
	for (int i = 0; i < M; i++) {
		int u, v; cin >> u >> v;
		--u;
		--v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	cin >> S >> F >> R;
	auto bfs = [&]() {
		vector<int> st;
		int top = 0;
		st[top++] = S;
	};
	int lo = some, hi = N;
	while (hi - lo > 1) {
		int mid = lo + (hi - lo) / 2;
		if (bfs(mid))
			lo = mid;
		else
			hi = mid;
	}
	cout << lo << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

    solve();
}

