#include "bits/stdc++.h"
#define int long long
#define sz(x) (int)(x).size()

using namespace std;




void solve() {
	int X, Y, N; cin >> X >> Y >> N;
	int ans = 1;
	if (Y % N == 0) {
		ans = X % N ? 1 : 0;
	} else {
		if (X < N - Y % N)
			ans = 2;
		else if (X >= N - Y % N && X < (N - Y % N) * 2)
			ans = 1;
		else if (X == (N - Y % N) * 2)
			ans = 0;
		else {
			X -= (N - Y % N) * 2;
			ans = X % N ? 1: 0;
		}
	}
	cout << ans << '\n';
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tt; cin >> tt;
	while (tt--) solve();
}
