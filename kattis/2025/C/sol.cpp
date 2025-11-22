#include<bits/stdc++.h>

using namespace std;

using ll = long long;

vector<vector<int>> adj;
vector<vector<int>> nfc;
stack<int> st;
vector<int> cyc;
vector<int> vis;
bool found = false;
vector<int> fp;

void dfs(int node) {
	if (vis[node] != 0) {
        found = true;
        return;
    }
	vis[node] = 2;
	st.push(node);
	for (auto X: adj[node]) {
		if (vis[X] != 0) {
			found = true;
			return;
		} else if (vis[X] == 0) {
			dfs(X);
		}
		if (found) return;
	}
	st.pop();
	vis[node] = 1;
}

void f(int node) {
	cerr << "node: " << node << '\n';
	if (vis[node] != 0) return;
	fp.push_back(node);
	vis[node] = 2;
	st.push(node);
	for (auto X: adj[node]) {
		if (vis[X] == 2) {
			found = true;
			while(!st.empty() && st.top() != X) {
				st.pop();
			}
			return;
		} else if (vis[X] == 0) {
			f(X);
		}
		if (found) return;
	}
	st.pop();
	vis[node] = 1;
}

void runcase() {
	int n, m;
	cin >> n >> m;
	adj.clear();
	nfc.clear();
	vis.clear();
	adj.resize(n);
	nfc.resize(n);
	vis.resize(n);
	fill(vis.begin(), vis.end(), 0);
	// does it clear with 0
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		--v;
		if (u < 0) {
			u = abs(u);
			--u;
			adj[u].emplace_back(v);
		} else {
			--u;
			nfc[u].emplace_back(v);
		}
	}
	f(0);
	// cout << found << '\n';
	ll ans = !found;


	for (auto X: vis) cerr << X << ' ';
	cerr << '\n';
	for (auto X: fp) {
		for (auto Y: nfc[X]) {
			// not sure.
			cerr << "X: " << X + 1 << ", Y: " << Y + 1 << '\n';
			if (vis[Y] == 0) {
				cerr << "enter the realm X: " << X + 1 << ", Y: " << Y + 1 << '\n';
				found = false;
				dfs(Y);
				ans += !found;
			}
		}
	}
	cerr << '\n';
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	runcase();
	return 0;
}
