#include<bits/stdc++.h>

using namespace std;

int main() {
	int n;
	while(1){
		cin >> n;
		if (n == -1) break;
		vector<vector<int>> adj(n);
		vector<long long> c(n);
		vector<int> vis(n, 0);
		for (int i = 0; i < n-1; i++) {
			int x;
			cin >> x;
			x--;
			adj[i + 1].push_back(x);
			adj[x].push_back(i + 1);
		}
		stack<pair<int, int>> st;
		st.push({0, 1});
		while(!st.empty()) {
			auto [cur, cost] = st.top();
			st.pop();
			c[cur] = cost;
			vis[cur] = 1;
			for (auto X: adj[cur]) {
				if (vis[X]) continue;
				st.push({X, cost + 1});
			}
		}
		long long ans = 0;
		long long mx = *max_element(c.begin(), c.end());
		for (auto X :c) {
			// cout << X << ' ';
			ans += ((X + 1) * X)/2;
		}
		cout << ans << '\n';
	}
	return 0;
}
