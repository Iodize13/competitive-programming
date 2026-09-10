#include "bits/stdc++.h"

using namespace std;


void solve() {

	int N; cin >> N;
	vector<int> A(N);
	for (auto &x: A) cin >> x;
	int cnt0 = 0;
	// int cnt1 = 0;
	for (int i = 1; i < N - 1; i++) {
		if (A[i] == 0) cnt0++;
	}
	if (A[0] == 0 && A[N - 1] == 0) {
		cout << "0\n";
	} else if (A[0] + A[N - 1] == 1) {
		cout << (cnt0 >= 1 ? 1 : -1) << '\n';
	} else if (A[0] + A[N - 1] == 2) {
		cout << (cnt0 >= 2 ? 2 : -1) << '\n';
	}
}

int main() {
	int tt; cin >> tt;
	while(tt--) solve();
}
