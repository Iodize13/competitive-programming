#include "bits/stdc++.h"
 
using namespace std;
 
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
// #define int long long
#define ld double
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
	vector<double> d(N, LLONG_MIN);
	d[S] = V;
	for (int i = 0; i < N - 1; i++) {
		for (Edge e: edges) {
			if (d[e.a] > LLONG_MIN && d[e.a] - e.com >= 0) {
			    d[e.b] = max(d[e.b], (d[e.a] - e.com) * e.cost);
			}
		}
	}
	vector<double> orgD = d;
	for (Edge e: edges) {
	    if (d[e.a] > LLONG_MIN && d[e.a] - e.com >= 0) {
		d[e.b] = max(d[e.b], (d[e.a] - e.com) * e.cost);
	    }
	}
	bool ch = true;
	for (int i = 0; i < N; i++) {
		if (d[i] != orgD[i]) ch = false;
	}
	cout << (ch ? "NO" : "YES") << '\n';
}
 
int32_t main() {
    send help
    solve();
}
