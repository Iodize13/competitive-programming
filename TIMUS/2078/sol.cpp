// #pragma GCC optimize("O3,unroll-loops")
#include "bits/stdc++.h"

using namespace std;

#define int long long
#define sz(x) (int)(x).size()



void solve() {
	const int N = 10;
	vector<int> A(N);
	for (auto &x: A) cin >> x;
	int mn = accumulate(A.begin(), A.begin() + 9, 0ll);
	// cerr << "mn: " << mn << '\n';
	{
		if (A.back() > 20 && A[8] == 10)
			mn += min(30ll, A.back() + A.back() % 20);
		else 
			mn += A.back();
	}
	while (A.back() > 10) {
		int tmp = A.back();
		A.back() = 10;
		A.push_back(max(0ll, tmp - 10));
	}
	vector<int> sum(2);
	vector<int> Q(2);
	for (int i = 0; i < sz(A); i++) {
		int cur = A[i];
		for (int j = 0; j < 2; j++) {
			if (Q[j]) {
				cur +=A[i];
			}
		}
		if (i < 9 &&  A[i] == 10) {
			swap(Q[0], Q[1]);
			Q[1] = 3;
		}
		for (int j = 0; j < 2; j++) {
			Q[j] -= min(1ll, Q[j]);
			if (A[i] != 10)
				Q[j] = 0;
		}
		sum[i >= 9] += cur;
	}
	cout << mn << ' ' << sum[0] + min(30ll, sum[1]) << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

    solve();
}

