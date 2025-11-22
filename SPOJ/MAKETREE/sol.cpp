#include <bits/stdc++.h>
//#include <cstdio>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define eb emplace_back
using ll=long long;
using pii=pair<int, int>;
using vi=vector<int>;
using ld=long double;

void DBG() {
	cerr << "]" << endl;
}
template<class H, class... T> void DBG(H h, T... t) {
	cerr << to_string(h);
	if(sizeof...(t))
		cerr << ", ";
	DBG(t...);
}
#ifdef LOCAL
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 42
#endif

ll n, m, q, k, y ,z;
string s, t;

const char nl = '\n';
ll a[(int)1e6+ 9];
ll c[(int)1e6+ 9];
vector<int> pa((int)1e6 + 1);

void findPa(int num, int se) {
	if (pa[num] == se) return;
	if (pa[num] == -1) {
		pa[num] = se;
		return;
	}
	findPa(pa[num], se);
}

void runcase(){
	cin >> n >> k;
	vector<vector<int>> adj(k);
	fill(pa.begin(), pa.end(), -1);
	for (int i = 0; i < k; i++) {
		cin >> q;
		for (int j =0; j < q; j++) {
			int x;
			cin >> x;
			--x;
			adj[i].eb(x);
		}
	}
	//cerr << "test" << endl;

	for (int i = 0; i < k; i++) {
		for (int j = 0; j < (int)adj[i].size(); j++) {
			int cur = adj[i][j];
			int l = 0;
			findPa(cur, i);
			// cout << "i: " << i << "j: " << j << ", findPa(cur): " << findPa(cur, i) << '\n';
			// while(true) {
			// 	if (pa[cur] == -1) {
			// 		pa[cur] = i;
			// 		break;
			// 	} else {
			// 		cur = pa[cur];
			// 	}
			// 	l++;
			// 	// cerr << l << endl;
			// 	assert(l <= (int)1e7);

			// 	cerr << "dbg: i: " << i << ", j: " << j << "cur: " << cur << '\n';
			// 	for (int h = 0; h < k; h++) {
			// 		cerr << pa[h] << ' ';
			// 	}
			// 	cerr << '\n';
			// }
		}
	}

	int root = -1;

	for (int i = 0; i < k; i++) {
		cerr << pa[i] << ' ';
	}
	cerr << '\n';
	for (int i = 0; i < k; i++) {
		if (root != 1 && pa[i] == -1) {
			pa[i] = root;
		}
		if (root == -1 && pa[i] == -1) {
			root = i;
			continue;
		}
	}
	for (int i = k; i < n; i++) {
		if (pa[i] == -1) {
			pa[i] = root;
		}
	}

	for (int i = 0; i < n; i++) cout << pa[i] + 1 << '\n';
	cerr << "root: " << root << '\n';	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int testcase(1);
	while(testcase--) runcase();
	return 0;
}
