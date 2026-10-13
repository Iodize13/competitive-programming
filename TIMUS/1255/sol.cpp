// #pragma GCC optimize("O3,unroll-loops")
#include "bits/stdc++.h"

using namespace std;

#define int long long
#define sz(x) (int)(x).size()



void solve() {
	int N, K; cin >> N >> K;
	vector<int> A(N + 1, -1);
	A[N] = -2;
	for (int i = N; i >= 0; i--) {
		if (i >= K && A[i] == -2)
			A[i - K] = -2;
		if (i - 2 * (i % K) >= 0 && A[i] == -2)
			A[i - 2 * (i % K)] = -2;
		if (i < K && A[i] == -2)
			A[i] = i * i;
	}
	// for (int i = 0; i <= N; i++)
	// 	cerr << A[i] << " \n"[i == N];
	int ans = (int)1e18;
	for (int i = 0; i <= N; i++)
		if (A[i] >= 0)
			ans = min(ans, A[i]);
	// cout << ans << '\n';
	cout << (N * N - ans) / K << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
}

