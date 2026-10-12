// #pragma GCC optimize("O3,unroll-loops")
#include "bits/stdc++.h"

using namespace std;

#define int long long
#define sz(x) (int)(x).size()



void solve() {
	int32_t S, R; cin >> S >> R;
	int mx = 32 - __builtin_clz(max(S, R));
	// cerr << "mx: " << mx << endl;
	vector<int> dp(mx + 1);
	for (int i = 2, j = 1; i <= mx; i++) {
		dp[i] = dp[i - 1] * 2 + j;
		j++;
		// cerr << "i, j: " << i << ' ' << j << endl;
	}
	// cerr << "case: 5" << endl;
	// for (int i = 0; i <= mx; i++) {
	// 	cerr << dp[i] << " \n"[i == mx];
	// }
	auto f = [&](int32_t n) {
		int ret = 0;
		int last = __builtin_ctz(n);
		// cerr << "last: " << last << endl;
		for (int i = mx; i >= last; i--) {
			if (((n >> i) & 1)) {
				ret += dp[i];
				if (i != last) ret += i - 1;
			}
			// cerr << "ret, i, dp[i], n >> i: " << ret << ' ' << i << ' ' << dp[i] << ' ' << (n >> i) << "\n";
		}
		return ret;
	};
	// cerr << "dbg: " << f(S) << ' ' << f(R) << "\n";
	cout << abs(f(S) - f(R)) << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

    solve();
}

