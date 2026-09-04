#include "bits/stdc++.h"

using namespace std;

#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
#define int long long
#define sz(x) (int)(x).size()
const int di[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
const int dj[8] = {-1, 1, 2, 2, 1, -1, -2, -2};
const int d4i[4] = {-1, 0, 1, 0};
const int d4j[4] = {0, -1, 0, 1};


void solve() {
	int N; cin >> N;
	vector<vector<int> > P(N, vector<int>(N, -1));
	vector<vector<short> > deg(N, vector<short>(N, 0));
	auto valid = [&] (int r, int c) {
		return r < N && r >= 0 && c < N && c >= 0;
	};
	{
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < 8; k++) {
					int nI = i + di[k];
					int nJ = j + dj[k];
					if (valid(nI, nJ)) deg[nI][nJ]++;
				}
			}
		}
	}
	// for (int i =0; i < N; i++) {
	// 	for (int j = 0; j < N; j++) {
	// 		cerr << deg[i][j];
	// 	}
	// 	cerr << '\n';
	// }
	for (int i = 0; i < (N - 1) / 2 + 1; i++) {
		for (int j = 0;j < (N - 1) / 2 + 1; j++) {
			vector<vector<int> > vis(N, vector<int>(N, 0));
			stack<array<int, 3> > st;
			st.push({i, j, 0});
			int cnt = 1;
			int mx = 0;
			while (!st.empty()) {
				auto &[r, c, dir] = st.top();
				mx = max(mx, sz(st));
				if (cnt == N * N) {
					while (!st.empty()) {
						cout << (char)(st.top()[1] + 'a') << st.top()[0] + 1 << '\n';
						st.pop();
					}
					return;
				}
				vector<pair<int, int> > ed;
				for (int d3 = 0; d3 < 8; d3++) {
					int nR = r + di[d3];
					int nC = c + dj[d3];
					if (valid(nR, nC) && !vis[nR][nC]) ed.push_back({nR, nC});
				}
				// cerr << sz(ed) << '\n';
				sort(ed.begin(), ed.end(), [&](const pair<int, int>& a, const pair<int, int>& b) {
					return deg[a.first][a.second] < deg[b.first][b.second];
				});
				if (dir == sz(ed)) {
					vis[r][c] = false;
					// if (sz(ed) != 0) {
					// 	for (int d3 = 0; d3 < 4; d3++) {
					// 		int nR = r + d4i[d3];
					// 		int nC = c + d4j[d3];
					// 		if (valid(nR, nC)) deg[nR][nC]++;
					// 	}
					// }
					st.pop();
					cnt--;
					continue;
				}

				if (dir == 0) {
					vis[r][c] = cnt;
					// for (int d2 = 0; d2 < 4; d2++) {
					// 	int aR = r + d4i[d2];
					// 	int aC = c + d4j[d2];
					// 	// cerr << aR << ' ' << aC << '\n';
					// 	if (valid(aR, aC)) {
					// 		// cerr << "enter\n";
					// 		deg[aR][aC]--;
					// 	}
					// }
				}
				auto [cR, cC] = ed[dir];
				st.push({cR, cC, 0});
				cnt++;
				dir++;
				// for (int k = 0; k < N; k++) {
				// 	for (int m = 0; m < N; m++) {
				// 		cerr << deg[k][m];
				// 	}
				// 	cerr << '\n';
				// }
				// cerr << '\n';
				// sleep(1);
			}
		}
	}
	cout << "IMPOSSIBLE\n";
}

int32_t main() {
	send help
		solve();
}
