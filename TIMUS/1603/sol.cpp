// #pragma GCC optimize("O3,unroll-loops")
#include "bits/stdc++.h"

using namespace std;

#define int long long
#define sz(x) (int)(x).size()
int d4i[4] = {0,1,0,-1};
int d4j[4] = {1,0,-1,0};



void solve() {
	int len = 4;
	vector<vector<char> > G(len, vector<char>(len));
	for (int i = 0; i < len; i++) {
		for (int j = 0; j< len; j++)cin>>G[i][j];
	}
	int N; cin >> N;
	vector<string> A(N);
	auto valid = [&](int r, int c) {
		return r >= 0 && r < len && c >= 0 && c < len;
	};
	for (auto &x: A)cin>>x;
	for (int k = 0; k < N; k++) {
		bool win = false;
		if (sz(A[k]) > 16) {
			cout << A[k] << ": NO\n";
			continue;
		}
		for (int i = 0;i < len; i++) {
			for (int j = 0; j < len; j++) {
				// can move up to boost performance.
				vector<vector<bool> > vis(len, vector<bool>(len, false));
				stack<array<int, 3> > st;
				st.push({i,j,0});
				string cur = "";
				while(!st.empty()) {
					auto &[r, c, act] = st.top();
					if (act == 4) {
						cur.pop_back();
						vis[r][c] = false;
						st.pop();
						continue;
					}
					if (act == 0) {
						cur += G[r][c];
						if (cur == A[k]) {
							win = true;
							break;
						}
					}
					vis[r][c] = true;
					int nR = r + d4i[act];
					int nC = c + d4j[act];
					if (valid(nR, nC) && !vis[nR][nC])
						st.push({nR,nC,0});
					act++;
				}
				if (win) break;
			}
			if (win) break;
		}
		cout << A[k] << ": " << (win ? "YES": "NO") << '\n';
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

    solve();
}

