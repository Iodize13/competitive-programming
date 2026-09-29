// #pragma GCC optimize("O3,unroll-loops")
#include "bits/stdc++.h"

using namespace std;

#define int long long
#define sz(x) (int)(x).size()



void solve() {
	int L, R; cin >> L >> R;
	auto f = [&](int n) {
		for (int i = 2; i <= n; i++)
			n -= n / i;
		return n;
	};
	cout << f(R) - f(L - 1) << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

    solve();
}

