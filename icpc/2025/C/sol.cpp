#include "bits/stdc++.h"
#define int long long
#define sz(x) (int)(x).size()

using namespace std;




void solve() {
	int N, K; cin >> N >> K;
	vector<int> A(N, 0);
	int mn = (int)1e6 + 1;
	int mx = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		mx = max(mx, A[i]);
		mn = min(mn, A[i]);
	}
	sort(A.begin(), A.end());
	vector<int> B(1e6 + 1, 0);
	int cur = 0;
	int L = mn;
	// cerr << "B[y]: ";
	for (int y = mx; y >= mn; y--) {
		auto en = upper_bound(A.begin(), A.end(), y) - A.begin();
		cur += N - en;
		B[y] = cur;
		// cerr << B[y] << ' ';
		if (cur > K) {
			break;
		}
		L = y;
	}
	// cerr << '\n';
	// cerr << "L: " << L << '\n';
	int curX = 0;
	int best = mx - mn;
	for (int x = mn; x <= mx; x++) {
		auto en = lower_bound(A.begin(), A.end(), x) - A.begin();
		curX += en;
		// cerr << "curX: " << curX << '\n';
		if (curX > K) break;
		int l = max(L, x) - 1, r = mx;
		// cerr << "before: l, r : " << l << ' ' << r << '\n';
		while (r - l > 1) {
			int mid = l + (r - l) / 2;
			// cerr << "mid, B[mid]: " << mid << ' ' << B[mid] << '\n';
			// cerr << "l, r: " << l << ' ' << r << '\n';
			if (curX + B[mid] > K) l = mid;
			else r = mid;
		}
		// cerr << '\n';
		// cerr << "x, r: " << x << ' ' << r << '\n';
		best = min(best, r - x);
	}
	cout << best << '\n';
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	solve();
}
