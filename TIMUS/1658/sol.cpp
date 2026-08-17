#include "bits/stdc++.h"

using namespace std;

#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
#define sz(x) (int)(x).size()
const int MxM = 8100 + 9;
// const int MxM = 15;
const int H = 900;
unsigned char dp[H + 1][MxM + 2];
vector<int> last(MxM + 1);

void init() {
	memset(dp, 0x7F, sizeof dp);
	dp[0][0] = 0;
	for (int i = 0; i < H; i++) {
		for (int j = i; j <= MxM; j++) {
			for (int k = 1; k < 10; k++) {
				if (i + k <= H && j + k * k <= MxM && dp[i][j] != 0x7F) {
					dp[i + k][j + k * k] = min(dp[i + k][j + k * k], (unsigned char)(dp[i][j] + 1));
					// cerr << "i+k, j+k*k: " << i+k << ", " << j+k*k << ", " << k <<'\n';
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
	if (s1 > H || s2 > 8100 || dp[s1][s2] == 0x7F) {
		cout << "No solution\n";
		return;
	} else {
// 		cerr << "9, 81: " << (int)dp[9][81] << '\n';
// 		cerr << "8, 80: " << (int)dp[8][80] << '\n';
		int i = s1, j = s2;
		string ans = "";
		int cur = dp[i][j];
		for (int l = 0; l < cur; l++) { 
			// cerr << "i, j: " << i << ", " << j << '\n';
			for (int k = 1; k <= 9; k++) {
				if (i - k >= 0 && j - k * k >= 0 && (dp[i - k][j - k * k] <= dp[i][j] - 1)) {
					ans += char(k + '0');
					i -= k;
					j -= k * k;
					break;
				}
			}
		}
		cout << (sz(ans) > 100 ? "No solution" :ans ) << '\n';
		// cout << ans << '\n';
	}
}

int32_t main() {
    send help

    init();
    int tt;
    cin >> tt;
    while (tt--) solve();
}

