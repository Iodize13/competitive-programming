#include "bits/stdc++.h"
#define int long long
#define sz(x) (int)(x).size()

using namespace std;


void solve() {
	int X, Y, K;cin >> X >> Y >> K;
	int sum = 0;
	int i = 0;
	while (X * 2 <= Y && i < K) {
		// cerr << Y % X << '\n';
		sum += Y % X;
		Y++;
		X++;
		i++;
		// sleep(1);
	}
	// cerr << '\n';
	// cerr << "i : " <<  i << '\n';
	// cerr << max(0ll, (K - i + 1)) << '\n';
	if (i < K) sum += (K - i) * (Y - X);
	cout << sum << '\n';
	// cerr << '\n';
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tt; cin >> tt;
	while(tt--) solve();
}
