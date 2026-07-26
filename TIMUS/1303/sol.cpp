#include "bits/stdc++.h"
 
using namespace std;
 
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
#define int long long
#define sz(x) (int)(x).size()
typedef vector<int> lnum;
const int di[4] = {0, 0, -1, 1};
const int dj[4] = {-1, 1, 0, 0};
 
 
 
void solve() {
	const int offset = 50000;
	int M; cin >> M;
	M += offset;
	vector<int> l2r(1000*100 + 1, -1);
	vector<int> r2l(1000*100 + 1, -1);
	int l, r;
	while (cin >> l) {
		cin >> r;
		if (l == 0 && r == 0) {
			break;
		}
		l += offset;
		r += offset;
		l2r[l] = max(l2r[l], r);
		if (r2l[r] == -1) r2l[r] = l;
		r2l[r] = min(r2l[r], l);
	}
	int idx = offset;
	int prev = -1;
	vector<pair<int, int> > ans;
	pair<int, int> tmp;
	while (true) {
		int cur = idx;
		for (int j = idx; j > prev; j--) {
		    if (l2r[j] > idx) {
			idx = l2r[j];
			tmp = {r2l[l2r[j]], l2r[j]};
		    }
		}
		ans.push_back(tmp);
		if (idx >= M) break;
		if (idx <= prev) { cout << "No solution\n"; return; }
		prev = cur;
	}
	sort(ans.begin(), ans.end());
	cout << sz(ans) << '\n';
	for (auto &[fi, se]: ans) cout << fi - offset << ' ' << se - offset << '\n';
}
 
int32_t main() {
    send help
 
    solve();
}
