// #pragma GCC optimize("O3,unroll-loops")
#include "bits/stdc++.h"

using namespace std;

#define int long long
#define sz(x) (int)(x).size()



void solve() {
	int N, K; cin >> N >> K;
	vector<int> dp(N);
	dp[0] = dp[1] = 1;
	for (int i = 2; i < N; i++)
		dp[i] = dp[i - 1] + dp[i - 2];
	
	vector<int> pref(N);
	for (int i = 1; i < N; i++)
		pref[i] = dp[i] + pref[i - 1];

	// for (int i = 0; i < N; i++) cerr << dp[i] << " \n"[i == N - 1];
	// for (int i = 0; i < N; i++) cerr << pref[i] << " \n"[i == N - 1];
	int ans = 0;
	while (K > 0) {
		K -= 2;
		if (K < 0) break;
		auto it = lower_bound(pref.begin(), pref.end(), K);
		if (it == pref.end()) {
			cout << "-1\n";
			return;
		}
		int j = it - pref.begin();
		// cerr << "K, j: " << K << ' ' << j << '\n';
		ans += (1ll << j);
		if (K == 0) break;
		K -= *prev(it, 1);
	}
	string S = "";
	for (int i = N - 1; i >= 0; i--)
		S += ((ans >> i) & 1) + '0';
	cout << S << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

    solve();
}

