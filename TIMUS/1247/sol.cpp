// #pragma GCC optimize("O3,unroll-loops")
#include "bits/stdc++.h"

using namespace std;

#define int long long
#define sz(x) (int)(x).size()



void solve() {
	int S, N; cin >> S >> N;
	vector<int> A(S);
	for (auto &x: A) {
		cin >> x;
		--x;
	}
	int mx = 0;
	bool ok = true;
	for (int i = 0; i < S; i++) {
		mx += A[i];
		if (mx < 0) 
			mx = 0;
		if (mx > N)
			ok = false;
	}
	cout << (ok ? "YES" : "NO") << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

    solve();
}

