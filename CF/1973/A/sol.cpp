#include<bits/stdc++.h>

using namespace std;

void runcase() {
	int a, b, c;
	cin >> a >> b >>c;
	int dp[31][31][31];
	for (int i = 0; i < 31; i++) {
		for (int j = 0; j < 31; j++) {
			for (int k = 0; k < 31; k++) {
				dp[i][j][k] = -INT_MAX;
			}
		}
	}
	dp[0][0][0] = 0;
	
	for (int i = 0; i <= a; i++) {
		for (int j = 0; j <= b; j++) {
			for (int k = 0; k <= c; k++) {
				if (i-1 >=0 && j-1>=0) dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-1][k] + 1);
				if (i-1 >=0&&k-1>=0) dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k-1] + 1);
				if (j-1>=0&&k-1>=0) dp[i][j][k] = max(dp[i][j][k], dp[i][j-1][k-1] + 1);
				if (i-2>=0) dp[i][j][k] = max(dp[i][j][k], dp[i-2][j][k]);
				if (j-2>=0) dp[i][j][k] = max(dp[i][j][k], dp[i][j-2][k]);
				if (k-2>=0) dp[i][j][k] = max(dp[i][j][k], dp[i][j][k-2]);
			}
		}
	}
	cout << (dp[a][b][c] <= -1000 ? -1 : dp[a][b][c]) << '\n';

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt;
	cin >> tt;
	while(tt--) {
		runcase();
	}
	return 0;
}
