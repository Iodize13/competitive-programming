#include "bits/stdc++.h"
 
using namespace std;
 
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
#define int long long
#define sz(x) (int)(x).size()
const int di[4] = {0, 0, -1, 1};
const int dj[4] = {-1, 1, 0, 0};
 
 
 
void solve() {
	int N, M; cin >> N >> M;
	vector<int> A(M);
	vector<int> vis(N);
	for (auto &x: A) cin >> x;
	sort(A.begin(), A.end());
	for (auto &x: A) {
		if ((x != 0 && !vis[x - 1]) || x == N) vis[x - 1]++;
		else vis[x]++;
	}
	bool ok = true;
	for (auto &x: vis) if (x > 1) ok = false;
	cout << (ok ? "YES" : "NO") << '\n';
}
 
int32_t main() {
    send help
    solve();
}
