#include "bits/stdc++.h"

using namespace std;

#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
#define int long long
#define sz(x) (int)(x).size()

void solve() {
	int N, S; cin >> N >> S;
	if (N < S) {
		cout << "0\n";
		return;
	}
	vector<int> dp(N + 1, 1);
	dp[N] = 1;
	for (int i = N - 1; i >= S; i--) {
		for (int j = i + 1; j <= N; j++) {
			if (((j - i) * 100) % i == 0) dp[i] = max(dp[i], dp[j] + 1);
		}
	}
	cout << dp[S] << '\n';
}

int32_t main() {
    send help

    solve();
}

