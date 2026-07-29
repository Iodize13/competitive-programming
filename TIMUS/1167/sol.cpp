#include "bits/stdc++.h"
 
using namespace std;
 
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
#define int long long
#define sz(x) (int)(x).size()
const int di[4] = {0, 0, -1, 1};
const int dj[4] = {-1, 1, 0, 0};
 
 
 
void solve() {
	int N, stable; cin >> N >> stable;
	vector<int> A(N);
	vector<vector<int> > dp(stable, vector<int>(N, INT64_MAX));
	vector<int> pref(N + 1);
	pref[0] = 0;
	for (auto &x: A) cin >> x;
	for (int i = 1; i < N + 1; i++) pref[i] = A[i - 1] + pref[i - 1];
	for (int i = 0; i < N; i++) {
	    int ones = pref[i + 1];
	    dp[0][i] = ones * (i + 1 - ones);
	}
	for (int i = 1; i < stable; i++) {
		for (int j = 0;j < N; j++) {
			for (int k = i - 1; k < j; k++) {
				int ones = pref[j + 1] - pref[k + 1];
				int cur = dp[i - 1][k] + ones * (j - k - ones);
				if (cur < dp[i][j]) {
					dp[i][j] = cur;
				}
			}
		}
	}
	cout << dp[stable - 1][N - 1] << '\n';
}
 
int32_t main() {
	send help
 
	solve();
}
