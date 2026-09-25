// #pragma GCC optimize("O3,unroll-loops")
#include "bits/stdc++.h"

using namespace std;

#define int long long
#define sz(x) (int)(x).size()



vector<array<int, 3> > isPrime;
vector<array<int, 3> > simpleSieve(int n) {
	vector<bool> prime(n + 1, true);
	prime[0] = prime[1] = false;
	for (int p = 2; p * p <= n; p++) {
		if (prime[p] == true) {
			for (int i = p * p; i <= n; i += p)
				prime[i] = false;
		}
	}

	vector<array<int, 3> > res;
	for (int i = 2; i < n; i++) {
		if (prime[i]) {
			for (int j = i, k = 1; j < 54; j *= j, k<<=1) {
				res.push_back({j, i, k});
			}
		}
	}
	sort(res.begin(), res.end());
	return res;
}

void solve() {
	int N; cin >> N;
	int res = 1;
	vector<int> P(54);
	bool ok = true;
	int j = 0;
	while (ok) {
		ok = false;
		for (auto &[v, base, e]: isPrime) {
			if (j != 0 && e != 1) continue;
			if (!(res > (int)1e18 / v) && res * v <= N) {
				res *= v;
				P[base] += e;
				ok = true;
			} else break;
		}
		j++;
	}
	int ans = 1;
	for (int i = 2; i < 54; i++) ans *= P[i] + 1;
	cout << res << ' ' << ans << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	isPrime = simpleSieve(54);
	int tt; cin >> tt;
	while (tt--) solve();
}

