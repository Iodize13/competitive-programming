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
		vector<vector<bool> > vis(N, vector<bool>(N, false));
		stack<array<int, 3> > st;
		st.push({i, j, 0});
		int cnt = 0;
		while (!st.empty()) {
			auto [r, c, dir] = st.top();
			st.pop();
			if (cnt == N * N) {
			    cout << (char)(c + 'a') << r + 1 << '\n';
			    while (!st.empty()) {
			    	if (st.top()[2] == -1) cout << (char)(st.top()[1] + 'a') << st.top()[0] + 1 << '\n';
				st.pop();
			    }
			    return;
			}
			if (dir == -1) {
				vis[r][c] = false;
				cnt--;
				continue;
			}
			st.push({r, c, -1});
			for (int k = 0; k < 8; k++) {
			    int nR = r + di[k];
			    int nC = c + dj[k];
			    if (nR < N && nR >= 0 && nC < N && nC >= 0 && !vis[nR][nC]) st.push({nR, nC, 0});
			}
			vis[r][c] = true;
			cnt++;
		}
	}
    }
    cout << "IMPOSSIBLE\n";
}
 
int32_t main() {
    send help
    solve();
}
