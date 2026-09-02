#include "bits/stdc++.h"

using namespace std;

#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
#define int long long
#define sz(x) (int)(x).size()



const bool TC = 0;
void solve() {
	int N, M;
	cin >> N >> M;
	vector<bitset<3000> > G(N, bitset<3000>());
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			bool x; cin >> x;
			G[i][j] = x;
		}
	}
	if (N == 1 || M == 1) {
		cout << "Yes\n";
		return;
	}
	bool ok = true;
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < M - 1; j++) {
			int cnt = 0;
			for (int k = 0; k < 2; k++) {
				for (int m = 0; m < 2; m++) {
					cnt += G[i + k][j + m];
				}
			}
			if (cnt == 3) {
				ok = false;
				break;
			}
		}
	}
	cout << (ok ? "Yes" : "No") << '\n';
}

int32_t main() {
	send help

		int tt = 1;
	if (TC) cin >> tt;
	while (tt--) solve();
}
