#include<bits/stdc++.h>

using namespace std;

using ll = long long;

vector<vector<char>> g(512, vector<char>(512));

ll f(int sx, int sy, int ex, int ey) {
	cerr << "dbg: " << sx << ' ' << sy << ' ' << ex << ' ' << ey << '\n';
	if (abs(sx - ex) == 1) {
		return 0;
	}
	vector<pair<int, int>> cntW;
	int tmp = 0;
	for (int i = sy; i < (ey + sy)/ 2 ; i++) {
		for (int j = sx; j < (ex + sx)/2; j++) {
			if (g[i][j]=='W') ++tmp;
		}
	}
	cntW.emplace_back(tmp, 0);
	tmp = 0;
	for (int i = (sy + ey) / 2; i < ey; i++) {
		for (int j = sx; j < (sx + ex)/2; j++) {
			if (g[i][j]=='W') ++tmp;
		}
	}
	cntW.emplace_back(tmp, 1);
	tmp = 0;
	for (int i = (sy + ey) / 2; i < ey; i++) {
		for (int j = (sx + ex) / 2; j < ex; j++) {
			if (g[i][j]=='W') ++tmp;
		}
	}
	cntW.emplace_back(tmp, 2);
	tmp = 0;
	for (int i = sy; i < (sy + ey)/ 2; i++) {
		for (int j = (sx + ex) / 2; j < ex; j++) {
			if (g[i][j]=='W') ++tmp;
		}
	}
	cntW.emplace_back(tmp, 3);
	ll ans = 0;
	sort(cntW.begin(), cntW.end());
	ans += (long long )pow(abs(sx - ex), 2) / 4 - cntW[3].first;
	ans += cntW[0].first;
	// cerr << cntW[0].first << ' ' << cntW[3].first << '\n';
	cerr << "dbg: ";
	for (auto [F, S]: cntW) cout << F << ' ' << S <<'\n';

	int dx[] = {sx, (sx + ex) / 2, sx, (sx + ex) /2};
	int dy[] = {sy, (sy + ey) / 2, (sy + ey) / 2, sy};

	for (int i = 0 ; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (i == j) continue;
			ans += min(ans, f(sx, sy, (sx + ex) / 2, (sy + ey) / 2) + f(
		}
	}
	if (cntW[1].second == 1) ans += f(sx, (sy + ey) / 2, (sx + ex) / 2, ey);
	if (cntW[1].second == 2) ans += f((sx + ex) / 2, (sy + ey) / 2, ex, ey);
	if (cntW[1].second == 3) ans += f((sx + ex) / 2, sy, ex, (sy + ey)/ 2);
	if (cntW[2].second == 0) ans += f(sx, sy, (sx + ex) / 2, (sy + ey) / 2);
	if (cntW[2].second == 1) ans += f(sx, (sy + ey) / 2, (sx + ex) / 2, ey);
	if (cntW[2].second == 2) ans += f((sx + ex) / 2, (sy + ey) / 2, ex, ey);
	if (cntW[2].second == 3) ans += f((sx + ex) / 2, sy, ex, (sy + ey)/ 2);
	return ans;
}

void runcase() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> g[i][j];
		}
	}
	cout << f(0, 0, n, n) << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while(t--) {
		runcase();
	}
	return 0;
}
