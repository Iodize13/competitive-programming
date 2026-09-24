// #pragma GCC optimize("O3,unroll-loops")
#include "bits/stdc++.h"

using namespace std;

#define int long long
#define sz(x) (int)(x).size()



const int MxM = 1000+1;
short dp[MxM][MxM][2];
char path[MxM][MxM];
const int d2i[2] = {-1, 0};
const int d2j[2] = {0, -1};

void solve() {
	int N; cin >> N;
	string S, T; cin >> S >> T;
	S = "$" + S;
	T = "$" + T;
	// cerr << (int)'$' << '\n';
	path[0][0] = -1;
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			if (i == 0 && j == 0) continue;
			for (int k = 0; k < 2; k++) {
				if (j != 0 && path[i][j - 1] != 0) {
				// if (j != 0) {
					dp[i][j][k] = dp[i][j - 1][k] + (T[j] - '0' == k);
					if (k == 1 && abs(dp[i][j][0] - dp[i][j][1]) <= 1) 
						path[i][j] = 2;
				}
				if (i != 0 && path[i - 1][j] != 0) {
				// if (i != 0) {
					// if (i == 4 && j == 0)
					// cerr << "S[i]: " << (int)S[i] << '\n';
					dp[i][j][k] = dp[i - 1][j][k] + (S[i] - '0' == k);
					if (k == 1 && abs(dp[i][j][0] - dp[i][j][1]) <= 1) {
						path[i][j] = 1;
					}
				}
			}
		}
	}
	// for (int i = 0; i <= N; i++) {
	// 	for (int j = 0; j <= N; j++) {
	// 		cerr << (int)path[i][j] << " \n"[j == N];
	// 	}
	// }
	// for (int i = 0; i <= N; i++) {
	// 	for (int j = 0; j <= N; j++) {
	// 		cerr << (int)dp[i][j][0] << ',' << (int)dp[i][j][1] << ' ';
	// 	}
	// 	cerr << '\n';
	// }
	int i = N, j = N;
	vector<int> ans;
	while (path[i][j] > 0) {
	// while (path[i][j] != 0) {
		ans.push_back(path[i][j]);
		int nR = i + d2i[path[i][j] - 1];
		int nC = j + d2j[path[i][j] - 1];
		i = nR, j = nC;
	}
	if (i == 0 && j == 0) {
		reverse(ans.begin(), ans.end());
		for (auto &x: ans) cout << x;
		cout << '\n';
	} else {
		// cerr << "i, j: " << i << ' ' << j << '\n';
		cout << "Impossible\n";
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

    solve();
}

