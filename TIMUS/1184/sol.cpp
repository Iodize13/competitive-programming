#include "bits/stdc++.h"
#define int long long
#define sz(x) (int)(x).size()

using namespace std;




void solve() {
	int N, K; cin >> N >> K;
	vector<int> A(N, 0);
	for (int i = 0; i < N; i++) {
		string s; cin >> s;
		int cut = s.find('.');
		string tmp2 = s.substr(0, cut);
		A[i] += 100*stoll(tmp2);
		string tmp3 = s.substr(cut + 1);
		int tmp = stoll(tmp3);
		A[i] += tmp;
	}
	auto f = [&](int x) {
		int sum = 0;
		for (int i = 0; i < N; i++) {
			sum += A[i] / x;
		}
		return sum >= K;
	};
	int lo = 0, hi = *max_element(A.begin(), A.end()) + 1;
	while (hi - lo > 1) {
		int m = lo + (hi - lo) / 2;
		if (f(m)) {
			lo = m;
		} else {
			hi = m;
		}
	}
	cout << lo / 100 << '.' << setw(2) << setfill('0') << lo % 100 << '\n';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
