// #pragma GCC optimize("O3,unroll-loops")
#include "bits/stdc++.h"

using namespace std;

#define int long long
#define sz(x) (int)(x).size()



void solve() {
	int N, P; cin >> N >> P;
	// cerr << "N, P: " << N << ' ' << P << '\n';
	vector<int> A(N);
	for (auto &x: A) cin >> x;
	// for (auto &x: A) cerr << x << ' ';
	// cerr << '\n';
	sort(A.begin(), A.end());
	vector<pair<int, int> > B;
	for (int i = 0; i < N; i++) {
		if (i == N - 1)
			B.push_back({A[i], i + 1});
		else if (A[i + 1] != A[i]) {
			B.push_back({A[i], i + 1});
		}
	}
	// for (int i = 0; i < sz(B); i++)
	// 	cerr << "(" << B[i].first <<"," << B[i].second << "), ";
	// cerr << '\n';
	int r = sz(B),l = 0;
	int prev = -1;
	int mx = 0;
	if (B[l].second * B[l].first <= P) {
		while (true) {
			// cerr << "mx: " << mx << '\n';
			r = sz(B);
			while (r - l > 1) {
				int m = l + (r - l) / 2;
				// cerr << "m: " << m << '\n';
				int tmp = B[m].second;
				if (prev != -1)
					tmp -= B[prev].second;
				int f = tmp * B[m].first;
				// cerr << "cal: " << f << '\n';
				if (f > P)
					r = m;
				else
					l = m;
			}
			// cerr << "prev, l: " << prev << ' ' << l << "\n\n";
			if (prev == l)
				break;
			prev = l;
			mx++;
		}
	} else {
		cout << "0 0\n";
		return;
	}
	cout << B[l].second << ' ' << mx << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

    solve();
}

