#include "bits/stdc++.h"
#define int long long
#define sz(x) (int)(x).size()

using namespace std;


void solve() {
	int X, Y; cin >> X >> Y;
	int S = X + Y;
	bool ok = false;
	int ans = 0;
	for (int mask = (1 << 29); mask > 0; mask >>= 1) {
		if ((mask & S) == 0) {
			if (mask & X) ok = true;
		} else {
			if (!ok) {
				ans |= (mask & X);
			} else {
				ans |= (mask & S);
			}
		}
	}
	cout << S << ' ' << X - ans << '\n';
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tt; cin >> tt;
	while(tt--) solve();
}
