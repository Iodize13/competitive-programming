#include "bits/stdc++.h"
 
using namespace std;
 
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
#define int long long
#define sz(x) (int)(x).size()
const int di[4] = {0, 0, -1, 1};
const int dj[4] = {-1, 1, 0, 0};
 
 
 
struct Edge {
	int a, b;
	double cost, com;
	Edge (int iA, int iB, double iCost, double iCom) {
		a = iA;
		b = iB;
		cost = iCost;
		com = iCom;
	}
};

void solve() {
	int N, M, S; cin >> N >> M >> S;
	const auto inf = numeric_limits<double>::infinity();
	--S;
	double V; cin >> V;
	vector<Edge> edges;
	for (int i = 0 ; i < M; i++) {
		int A, B; cin >> A >> B;
		--A, --B;
		double RAB, CAB, RBA, CBA; cin >> RAB >> CAB >> RBA >> CBA;
		Edge AB(A, B, RAB, CAB);
		Edge BA(B, A, RBA, CBA);
		edges.push_back(AB);
		edges.push_back(BA);
	}
	vector<double> d(N, -inf);
	d[S] = V;
	int x;
	for (int i = 0; i < N; i++) {
		x = -1;
		for (Edge e: edges) {
			if (d[e.a] > -inf && d[e.a] - e.com >= 0)
				if (d[e.b] < (d[e.a] - e.com) * e.cost) {
					d[e.b] = min(inf, (d[e.a] - e.com) * e.cost);
					x = e.b;
				}
		}
	}
	cout << (x == -1 ? "NO" : "YES") << '\n';
}
 
int32_t main() {
    send help
    solve();
}
