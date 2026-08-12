#include "bits/stdc++.h"

using namespace std;

#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
#define int long long
#define sz(x) (int)(x).size()


void solve() {
	const int inf = (int)2e18 + 5;
	string S; cin >> S;
	int N = sz(S);
	vector<vector<bool> > ok(N, vector<bool>(N, false));
	vector<int> dp(N + 1, inf), p(N + 1, 0);
	vector<string> ans;
	dp[0] = 0;
	for (int i = 0; i < N; i++) ok[i][i] = true;
	for (int len = 1; len <= N; len++) {
		for (int i = 0, j = len - 1; j < N; i++, j++) {
			if (S[i] == S[j])
				ok[i][j] = (i + 1 <= j - 1) ? ok[i + 1][j - 1] : true;
		}
	}
	// cerr << "enter 5" << endl;
	for (int j = 1; j <= N; j++) {
		for (int i = 0; i < j; i++) {
			if (dp[i] + 1 < dp[j] && ok[i][j - 1]) {
				// cerr << "enter 5.5" << endl;
				dp[j] = dp[i] + 1;
				p[j] = i;
			}
		}
	}
	// cerr << "enter 6" << endl;

	int cur = N;
	while (cur) {
		ans.push_back(S.substr(p[cur], cur - p[cur]));
		cur = p[cur];
	}
	// cerr << "enter 7" << endl;
	reverse(ans.begin(), ans.end());
	cout << dp[N] << '\n';
	for (auto x: ans) cout << x << ' ';
}

int32_t main() {
	send help

		solve();
}
