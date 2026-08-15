#include "bits/stdc++.h"

using namespace std;

#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
#define int long long
#define sz(x) (int)(x).size()
const int MxM = 1000*10 + 9;
// const int MxM = 15;
vector<vector<int> > dp(MxM + 1, vector<int>(MxM + 1, -1));
vector<int> last(MxM + 1);

void init() {
	dp[0][0] = 0;
	for (int i = 0; i < MxM; i++) {
		for (int j = i; j <= MxM; j++) {
			for (int k = 1; k < 10; k++) {
				if (i + k <= MxM && j + k * k <= MxM && dp[i][j] != -1) {
					dp[i + k][j + k * k] = k;
					// cerr << "i+k, j+k*k: " << i+k << ", " << j+k*k << ", " << k <<'\n';
					last[i + k] = max(last[i + k], j + k * k);
				}
			}
		}
	}
	// for (int i = 0; i < MxM; i++) {
	// 	for (int j = 0; j < MxM; j++) cout << dp[i][j];
	// 	cerr << '\n';
	// }
}

void solve() {
	int s1, s2; cin >> s1 >> s2;
	// why this doesn't runtime error?
	if (dp[s1][s2] == -1) {
		cout << "No solution.\n";
		return;
	} else {
		int i = s1, j = s2;
		while(dp[i][j]) {
			// cerr << "i, j: " << i << ", " << j << '\n';
			cout << dp[i][j];
			int cur = dp[i][j];
			i -= cur;
			j -= cur * cur;
		}
		cout << '\n';
	}
}

int32_t main() {
    send help

    init();
    int tt;
    cin >> tt;
    while (tt--) solve();
}

