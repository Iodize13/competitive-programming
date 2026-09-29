// #pragma GCC optimize("O3,unroll-loops")
#include "bits/stdc++.h"

using namespace std;

#define int long long
#define sz(x) (int)(x).size()



void solve() {
	int N, M; cin >> N >> M;
	vector<vector<bool> > G(N, vector<bool>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			bool x; cin >> x;
			G[i][j] = x;
		}
	}

	int mn = (int)1e18;
	int ans[2];
	for (int i = 0; i < M; i++) {
		for (int j = i + 1; j < M; j++) {
			vector<int> sets(4);
			for (int k = 0; k < N; k++) {
				sets[(((int)G[k][i] << 1) | G[k][j])]++;
			}
			int cur = *max_element(sets.begin(), sets.end());
			if (cur < mn) {
				mn = cur;
				ans[0] = i;
				ans[1] = j;
			}
		}
	}
	cout << mn << '\n';
	cout << ans[0] + 1 << ' ' << ans[1] + 1 << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

    solve();
}

