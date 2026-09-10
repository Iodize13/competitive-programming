// #pragma GCC optimize("O3,unroll-loops")
#include "bits/stdc++.h"

using namespace std;

#define int long long
#define sz(x) (int)(x).size()



void solve() {
	int N; cin >> N;
	vector<int> A(N);
	for (auto &x: A)cin >> x;
	int best = *max_element(A.begin(), A.end());
	for (int s = 0; s < 2; s++) {
		for (int i = s, sum = 0; i < N; i+=2) {
			best = max(best, sum += A[i]);
			// cerr << "best, s, i: " << best << ' ' << s << ' ' << i << '\n';
			if (i + 1 < N) sum -= A[i + 1];
			if (sum < 0) {
				sum = 0;
			}
			best = max(best, sum);
		}
	}
	cout << best << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

    solve();
}

