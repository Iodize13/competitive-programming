// #pragma GCC optimize("O3,unroll-loops")
#include "bits/stdc++.h"

using namespace std;

#define int long long
#define sz(x) (int)(x).size()



void solve() {
	int N, P;
	while (cin >> N) {
		cin >> P;
		if (N == 0 && P == 0) return;
		int x = 1;
		for (int i = 1; i <= N; i++) {
			x = x * (i % P) % P;
		}
		cout << x << '\n';
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

    solve();
}

