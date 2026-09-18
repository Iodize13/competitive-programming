// #pragma GCC optimize("O3,unroll-loops")
#include "bits/stdc++.h"

using namespace std;

#define int long long
#define sz(x) (int)(x).size()



// char dp[100 + 1][1000 + 2]// ;
char cnt[100 + 1][100000 + 2];

void solve() {
	int W; cin >> W;
	int N; cin >> N;
	vector<int> A(N);
	for (auto &x: A)cin >> x;
	cnt[0][0] = 1;
	for (int i = 0; i < N; i++) {
		for (int sum = W; sum >= 0; sum--) {
			if (i != 0){
				cnt[i][sum] = cnt[i - 1][sum];
				if (sum - A[i] >= 0)cnt[i][sum]+= cnt[i - 1][sum - A[i]];
			}

			else {
				if (sum - A[i] >= 0)cnt[i][sum] = cnt[i][sum-A[i]];
			}
			cnt[i][sum] = min(cnt[i][sum], (char)2);
		}
	}
	// for (int i = 0; i < N; i++) {
	// 	for (int j = 0; j <= W; j++)cerr << cnt[i][j] << ' ';
	// 	cerr << '\n';
	// }
	if (cnt[N - 1][W] == 0) {
		cout << "0\n";
	} else if (cnt[N - 1][W] != 1) {
		cout << "-1\n";
	} else {
		int i = N - 1, sum = W;
		vector<bool> vis(N, false);
		while (sum > 0) {
			// cerr << "sum, i: " << sum << ' ' << i << endl;
			if (i==0) {
				vis[i] = true;
				break;
			}
			if (cnt[i-1][sum]) {
			} else {
				sum = sum - A[i];
				vis[i] = true;
			}
			i--;
		}
		for (i = 0; i < N; i++) {
			if (!vis[i]) cout << i + 1 << ' ';
		}
		cout << '\n';
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

    solve();
}

