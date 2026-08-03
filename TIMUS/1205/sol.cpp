#include "bits/stdc++.h"
 
using namespace std;
 
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
#define int long long
#define ld long double
#define sz(x) (int)(x).size()
const int di[4] = {0, 0, -1, 1};
const int dj[4] = {-1, 1, 0, 0};
 
 
struct Point {
	ld x, y;
};

ld lineDist(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
 
void solve() {
	ld foot, train;
	const auto inf = numeric_limits<ld>::infinity();
	int N; cin >> foot >> train >> N;
	vector<ld> dist(N + 2, inf);
	vector<Point> C(N);
	vector<vector<pair<int, ld> > > G(N + 2);
	vector<int> par(N + 2);
	for (Point &p: C) cin >> p.x >> p.y;
	int u, v;
	while (cin >> u) {
		cin >> v;
		if (u == 0 && v == 0) break;
		--v;
		--u;
		ld tmp = lineDist(C[u], C[v]) / train;
		G[u].push_back({v, tmp});
		G[v].push_back({u, tmp});
	}
	for (int i = 0; i < 2; i++) {
		Point tmp; cin >> tmp.x >> tmp.y;
		C.push_back(tmp);
	}
	for (int i = 0; i < N + 2; i++) {
		for (int j = i + 1; j < N + 2; j++) {
		    ld tmp = lineDist(C[i], C[j]) / foot;
		    G[i].push_back({j, tmp});
		    G[j].push_back({i, tmp});
		}
	}
	dist[N] = 0;
	priority_queue<pair<ld, int>, vector<pair<ld, int> >, greater<pair<ld, int> > > pq;
	pq.push({0, N});
	while (!pq.empty()) {
		auto [cdist, node] = pq.top();
		pq.pop();
		if (cdist != dist[node]) continue;
		for (auto &[next, cost]: G[node]) {
			if (cdist + cost < dist[next]) {
				dist[next] = cdist + cost;
				pq.push({dist[next], next});
				par[next] = node;
			}
		}
	}
	vector<int> ans;
	int cur = N + 1;
	while (cur != N) {
		ans.push_back(cur);
		cur = par[cur];
	}
	int cnt = 0;
	for (int i = sz(ans) - 1; i >= 0; i--) if (ans[i] != N && ans[i] != N + 1) cnt++;
	cout << fixed << setprecision(7) << dist[N + 1] << '\n';
	cout << cnt << ' ';
	for (int i = sz(ans) - 1; i >= 0; i--) if (ans[i] != N && ans[i] != N + 1) cout << ans[i] + 1 << ' ';
}
 
int32_t main() {
    send help
    solve();
}
