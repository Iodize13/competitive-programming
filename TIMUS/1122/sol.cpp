#include "bits/stdc++.h"
#define bs bitset<30>

using namespace std;
const int d9i[9] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
const int d9j[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};


void solve() {
	const int N = 4;
	int board = 0;
	vector<vector<char> > pat(3, vector<char>(3));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char x; cin >> x;
			board |= (x == 'W' ? (1 << (i * N + j)) : 0);
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> pat[i][j];
		}
	}
	queue<pair<int, int> > que;
	vector<bool> vis((1 << (N * N)), false);
	que.push({0, 0});
	que.push({((1 << (N * N)) - 1), 0});
	int ans = -1;
	while (!que.empty()) {
		auto [cur, cnt] = que.front();
		// for (int i = 0; i < N; i++) {
		// 	for (int j = 0; j < N; j++) {
		// 		cerr << ((cur >> (N * N - i * N - j - 1)) & 1);
		// 	}
		// 	cerr << '\n';
		// }
		// 	cerr << '\n';
		que.pop();
		if (cur == board) {
			ans = cnt;
			break;
		}
		if (vis[cur]) continue;
		vis[cur] = 1;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				int tmp = cur;
				for (int dir = 0; dir < 9; dir++) {
					int nR = i + d9i[dir];
					int nC = j + d9j[dir];
					if (nR >= 0 && nR < N && nC >= 0 && nC < N
					&& pat[d9i[dir] + 1][d9j[dir] + 1] == '1') 
						tmp ^= (1 << (nR * N + nC));
				}
				que.push({tmp, cnt + 1});
			}
		}
	}
	cout << (ans == -1 ? "Impossible" : to_string(ans)) << '\n';
}


int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
}
