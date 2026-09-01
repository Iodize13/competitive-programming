#include "bits/stdc++.h"

using namespace std;

#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
#define int long long
#define sz(x) (int)(x).size()
const int di[4] = {0, 1, 0, -1};
const int dj[4] = {1, 0, -1, 0};


void solve() {
	int N; cin >> N;
	vector<vector<char> >  G(N, vector<char>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> G[i][j];
		}
	}
	stack<pair<int, int> > st;
	st.push({0,0});
	st.push({N - 1, N - 1});
	vector<vector<bool> > vis(N, vector<bool>(N, false));
	int cnt = 0;
	while(!st.empty()) {
		auto [r, c] = st.top();
		st.pop();
		if (vis[r][c]) continue;
		vis[r][c] = true;
		for (int dir = 0; dir < 4; dir++) {
			int ni = r + di[dir];
			int nj = c + dj[dir];
			if (ni >= N || ni < 0 || nj >= N || nj < 0 || G[ni][nj] != '.') {
				// cerr << "ni, nj: " << ni << ' ' << nj << '\n';
				cnt++;
			}
			if (ni < N && ni >= 0 && nj < N && nj >= 0 && !vis[ni][nj] && G[ni][nj] == '.') {
				st.push({ni, nj});
			}
		}
	}
	// for (int i = 0; i < N; i++) {
	// 	for (int j = 0; j < N; j++) {
	// 		cerr << vis[i][j];
	// 	}
	// 	cerr << '\n';
	// }
	cout << (cnt - 4) * 9 << '\n';
}

int32_t main() {
    send help

	solve();
}
