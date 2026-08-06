#include <bits/stdc++.h>
#define int long long
#define sz(x) (int)(x).size()
const int di[2] = {1, 0};
const int dj[2] = {0, 1};

using namespace std;

void sol() {
	int H, W; cin >> H >> W;
	vector<vector<int> > G(W);
	vector<int> lasts(W);
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			char x; cin >> x;
			if (x == 'C') {
			    G[j].push_back(i);
			    lasts[j]++;
			}
		}
	}
	int cnt = 0;
	for (int j = 0; j < W; j++) {
		if (!G[j].empty() && lasts[j] != 0) {
		    int at = G[j][lasts[j] - 1];
		    for (int k = j + 1; k < W; k++) {
			int tmp = lower_bound(G[k].begin(), G[k].begin() + lasts[k], at) - G[k].begin();
			if (tmp >= lasts[k]) continue;
			else {
			    at = G[k][lasts[k] - 1];
			    lasts[k] = tmp;
			}
		    }
		    cnt++;
		}
	}

	cout << cnt << '\n';
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	sol();
}
