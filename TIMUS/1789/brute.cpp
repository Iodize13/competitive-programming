#include "bits/stdc++.h"
 
using namespace std;
 
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
#define int long long
#define sz(x) (int)(x).size()
 
 
 
void solve() {
	int N; cin >> N;
	auto checker = [&](int state, int x) {
		state &= ~(1 << x);
		return ((state << 1) & ~(1 << N)) | (state >> 1);
	};
	queue<int> que;
	vector<pair<int, int> > A((1<<N));
	vector<bool> vis((1<<N), false);
	que.push((1<<N) - 1);
	A[(1<<N) - 1] = {-1, -1};
	while (!que.empty()) {
		auto cur = que.front();
		que.pop();
		if (cur == 0) break;
		if (vis[cur]) continue;
		vis[cur] = true;
		for (int i = 0; i < N; i++) {
			int state = checker(cur, i);
			if (vis[state]) continue;
			que.push(state);
			A[state] = {cur, i};
		}
	}
	int path = 0;
	while (path != (1 << N) - 1) {
		for (int i = 0; i < 31; i++) {
			cerr << ((A[path].first >> i) & 1);
		}
		cerr << '\n';
		cerr << A[path].second + 1<< ' ';
		path = A[path].first;
	}
}
 
int32_t main() {
    send help
 
    solve();
}
