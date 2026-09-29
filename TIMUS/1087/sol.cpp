// #pragma GCC optimize("O3,unroll-loops")
#include "bits/stdc++.h"

using namespace std;

#define int long long
#define sz(x) (int)(x).size()



void solve() {
	int N, M; cin >> N >> M;
	const int inf = (int)1e9;
	vector<int> A(M), dp(N + 1, inf);
	for (auto &x: A)cin >> x;
	for (int i = 0; i < M; i++)
		if (A[i] <= N)
			dp[A[i]] = 2;

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			if (i + A[j] <= N) {
				if (dp[i] == 2)
					dp[i + A[j]] = 1;
				if (dp[i] == 1 && dp[i + A[j]] == inf)
					dp[i + A[j]] = 2;
			}
		}
	}
	cout << dp[N] << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

    solve();
}

