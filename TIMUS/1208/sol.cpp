#include "bits/stdc++.h"

using namespace std;

#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
#define int long long
#define sz(x) (int)(x).size()


void solve() {
	int K; cin >> K;
	vector<vector<string> > A(K);
	vector<string> names;
	for (int i = 0; i < K; i++) {
		for (int j = 0; j < 3; j++) {
			string x; cin >> x;
			A[i].push_back(x);
			names.push_back(x);
		}
	}
	sort(names.begin(), names.end());
	names.resize(unique(names.begin(), names.end()) - names.begin());
	stack<array<int, 3> > st;
	vector<string> cur;
	st.push({0, 0, 0});
	vector<bool> vis(K);
	int ans = 1;
	while (!st.empty()) {
		auto &top = st.top();
		// cerr << top[0] << ' ' << top[1] << ' ' << top[2] << endl;
		if (top[0] == K) {
			ans = max(ans, top[2]);
			st.pop();
			continue;
		}
		if (top[1] == 0) {
			bool ok = true;
			top[1]++;
			for (int i = 0; i < 3; i++) {
				if (find(cur.begin(), cur.end(), A[top[0]][i]) != cur.end()) {
					ok = false;
					break;
				}
			}
			if (!ok) {
				continue;
			}
			for (int i = 0; i < 3; i++) {
				cur.push_back(A[top[0]][i]);
			}
			st.push({top[0] + 1, 0, top[2] + 1});
			vis[top[0]] = true;
		} else if (top[1] == 1) {
			// have problem when never push
			if (vis[top[0]]) 
				for (int i = 0; i < 3; i++) cur.pop_back();

			vis[top[0]] = false;
			st.push({top[0] + 1, 0, top[2]});
			top[1]++;
		} else {
			st.pop();
		}
	}
	cout << ans << '\n';
}

int32_t main() {
    send help

    solve();
}
