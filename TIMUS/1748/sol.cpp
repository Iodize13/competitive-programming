// #pragma GCC optimize("O3,unroll-loops")
#include "bits/stdc++.h"
#include <unistd.h>


using namespace std;

#define int long long
#define sz(x) (int)(x).size()



vector<int> isPrime;
vector<int> simpleSieve(int n) {
	vector<bool> prime(n + 1, true);
	prime[0] = prime[1] = false;
	for (int p = 2; p * p <= n; p++) {
		if (prime[p] == true) {
			for (int i = p * p; i <= n; i += p)
				prime[i] = false;
		}
	}

	vector<int> res;
	for (int i = 2; i < n; i++) {
		if (prime[i]) {
			res.push_back(i);
		}
	}
	return res;
}
vector<array<int, 3> > st(13);

void solve() {
	int N; cin >> N;
	vector<int> A(N), ans(N), divisor(N);
	for (auto &x: A)cin >> x;
	int top = 0;
	st[top++] = {1, 1, 0};
	vector<int> mx = {	9, 5, 3, 4, 3, 3,
						2, 1, 1, 1, 1, 1};
	const int inf = (int)1e9;
	int iter = 0;
	vector<bool> ov(13, false);
	while (top) {
		// if (iter == 1000) break;
		iter++;
		auto &[v, d, act] = st[top - 1];
		if (top == 13) {
			top--;
			// cerr << '\n';
			continue;
		}
		for (int j = 0; j < N; j++) {
			if (v <= A[j]) {
				if (d * (act + 1) > divisor[j]) {
					divisor[j] = d * (act + 1);
					ans[j] = v;
				} else if (d * (act + 1) == divisor[j]) {
					ans[j] = min(ans[j], v);
				}
			}
		}
		if (ov[top - 1] || act == min(mx[top - 1], top > 1 ? st[top - 2][2] - 1: inf) + 1) {
			top--;
			continue;
		}
		// cerr << "top, v, d, act: " << top << ' ' << v << ' ' << d << ' ' << act << endl;
		st[top] = {v, d * (act + 1), 0};
		ov[top] = false;
		if ((int)1e18 / isPrime[top - 1] < v) {
			ov[top - 1] = true;
			continue;
		}
		act++;
		v *= isPrime[top - 1];
		top++;
	}
	for (int i = 0; i < N; i++) {
		cout << ans[i] << ' ' << divisor[i] << '\n';
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	isPrime = simpleSieve(38);
	solve();
}

// handle case 1
// if wrong just stress test. 
