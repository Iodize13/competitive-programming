#include "bits/stdc++.h"
 
using namespace std;
 
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
#define int long long
#define sz(x) (int)(x).size()
const int di[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
const int dj[8] = {-1, 1, 2, 2, 1, -1, -2, -2};
 
 
void solve() {
    int N; cin >> N;
    vector<vector<int> > P(N, vector<int>(N, -1));
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
			if (dir == 8) {
				vis[r][c] = false;
				st.pop();
				cnt--;
				continue;
			}

			int nR = r + di[dir];
			int nC = c + dj[dir];
			vis[r][c] = cnt;
			if (nR < N && nR >= 0 && nC < N && nC >= 0 && !vis[nR][nC]) {
			    st.push({nR, nC, 0});
			    cnt++;
			}
			dir++;
		}
	}
    }
    cout << "IMPOSSIBLE\n";
}
 
int32_t main() {
    send help
    solve();
}
