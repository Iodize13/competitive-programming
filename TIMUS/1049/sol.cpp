#include "bits/stdc++.h"
#define int long long
#define sz(x) (x).size()

using namespace std;

void solve() {
	int N = 10;
	map<int, int> P;
	// handle all 1
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		for (int j = 2; j * j <= x; j++) {
			while (x % j == 0) {
				P[j]++;
				x /= j;
			}
		}
		// prime
		if (x > 1) P[x]++;
		// handle 1/2 
	}
	int ans = 1;
	for (auto it = P.begin(); it != P.end(); it++) {
		// cerr << "it" << it->first << ' ' << it->second << '\n';
		ans *= it->second + 1;
	}
	cout << (ans % 10) ? (ans % 10) : 10 << '\n';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
