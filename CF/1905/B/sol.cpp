#include<bits/stdc++.h>

using namespace std;

void runcase() {
	int n;
	cin >> n;
	vector<vector<int>> adj(n);
	for (int i =0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		--u;
		--v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	stack<int> st;
	st.push(0);
	vector<int> vis(n, 0);
	long long ans = 0;
	while(!st.empty()) {
		auto cur = st.top();
		st.pop();
		vis[cur] = 1;
		for (auto X: adj[cur]) {
			if (vis[X]) continue;
			st.push(X);
		}
	}
	cout << ans <<'\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while(t--) {
		runcase();
	}
}
