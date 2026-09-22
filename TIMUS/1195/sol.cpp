// #pragma GCC optimize("O3,unroll-loops")
#include "bits/stdc++.h"

using namespace std;

#define int long long
#define sz(x) (int)(x).size()



void solve() {
	const int N = 3;
	vector<vector<char> > G(N, vector<char>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)cin >> G[i][j];
	}
	auto win = [&]() {
		bool ch = ((G[0][0] == G[1][1]) && G[1][1] == G[2][2])
					|| ((G[0][2] == G[1][1]) && G[1][1] == G[2][0]);
		for (int i = 0; i < N; i++) {
			ch |= (G[i][0] == G[i][1]) && G[i][1] == G[i][2];
			ch |= (G[0][i] == G[1][i]) && G[1][i] == G[2][i];
		}
		return ch;
	};
	auto turn = [&](int who, bool pv) {
		string dir = "OX";
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++){ 
				if (G[i][j] == '#') {
					G[i][j] = dir[who ^ pv];
					if (win()) {
						G[i][j] = dir[who];
						return true;
					} else {
						G[i][j] = '#';
					}
				}
			}
		}
		return false;
	};
	auto f = [&](int who) {
		int k = 0;
		while (k < 2) {
			if (turn(who, false)) {
				// cerr << "case 6\n";
				cout << (who ? "Crosses" : "Ouths") << " win\n";
				return true;
			} else {
				// cerr << "case 7\n";
				turn(who, true);
			}
			k++;
			who ^= 1;
		}
		return false;
	};
	int k = 0;
	int who = 1;
	while (k < 3) {
		if (turn(who, false)) {
			cout << (who ? "Crosses" : "Ouths") << " win\n";
			return;
		} else {
			if (turn(who, true)) {
			} else {
				auto tmp = G;
				for (int i = 0; i < N; i++) {
					for (int j = 0; j < N; j++) {
						if (G[i][j] == '#') {
							G[i][j] = 'X';
							if (f(0)) {
								return;
							}
							// for (int m = 0; m < N; m++) {
							// 	for (int n = 0; n < N; n++) {
							// 		cerr << G[m][n];
							// 	}
							// 	cerr << '\n';
							// }
							// cerr << '\n';
							G = tmp;
						}
					}
				}
			}
		}
		who ^= 1;
		k++;
	}
	cout << "Draw\n";
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

    solve();
}

