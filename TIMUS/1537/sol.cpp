// #pragma GCC optimize("O3,unroll-loops")
#include "bits/stdc++.h"

using namespace std;

// #define int long long
#define sz(x) (int)(x).size()



void solve() {
	int K, P; cin >> K >> P;
	vector<int> A(K + 1);
	if (K != 1)
		A[2] = 1;
	for (int i = 3; i <= K; i++) {
		if (i % 2 == 0) 
			A[i] = (A[i / 2] + A[i - 1]) % P;
		else 
			A[i] = A[i - 1];
	}
	cout << A[K] % P << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

    solve();
}

