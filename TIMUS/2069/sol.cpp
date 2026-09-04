#include "bits/stdc++.h"
#define int long long
#define sz(x) (int)(x).size();

using namespace std;

void solve() {
	int N, M; cin >> N >> M;
	vector<int> c(N, 0);
	vector<int> r(M, 0);
	for (int i = 0; i < N; i++) {
		cin >> c[i];
	}
	for (int i = 0; i < M; i++) {
		cin >> r[i];
	}
	int ans = max(min(r[0], c[N - 1]), min(r[M - 1], c[0]));
	for (int i = 1; i < N - 1; i++) {
		ans = max(ans, min({r[0], c[i], r[M - 1]}));
	}
	for (int i = 1; i < M - 1; i++) {
		ans = max(ans, min({c[0], r[i], c[N - 1]}));
	}
	cout << ans << '\n';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
