#include "bits/stdc++.h"
#define int long long
#define sz(x) (int)(x).size()

using namespace std;


void solve() {
	int X, Y; cin >> X >> Y;
	int mx = (X ^ Y);
	int mn = 0;
	int i = 0;
	while (X >= 0) {
		// cerr << "x, y: " << X << ' ' << Y << '\n';
		// cerr << "xor: " << (X ^ Y) << '\n';
		if ((X ^ Y)> mx) {
			mn = i;
			mx = (X ^ Y);
		}
		X--;
		Y++;
		i++;
	}
	cout << mx << ' ' << mn << '\n';
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tt; cin >> tt;
	while(tt--) solve();
}
