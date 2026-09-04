#include "bits/stdc++.h"
#define int long long
#define sz(x) (int)(x).size()

using namespace std;

void solve() {
	int N; cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	vector<int> B = A;
	sort(B.begin(), B.end());
	vector<int> ans;
	for (int i = 0; i < N; i++) {
		if (B[i] != A[i]) {
			// cerr << B[i] << ' ' << A[i] << '\n';
			ans.push_back(i);
		}
	}
	if ((int)ans.size() >= 3) {
		int tmp = sz(ans);
		for (int i = 0; i < tmp; i++) ans.pop_back();
		reverse(B.begin(), B.end());
		for (int i = 0; i < N; i++) {
			if (B[i] != A[i])ans.push_back(i);
		}
		if (sz(ans) >= 3) {
			cout << "No hope\n";
			return;
		} else if (sz(ans) == 0) {
			cout << "Nothing to do here\n";
			return;
		}
		cout << "Yes\n";
		for (int i = 0; i < sz(ans); i++) {
			cout << ans[i] + 1 << ' ';
		}
		cout << '\n';
	} else if (sz(ans) == 0) {
		cout << "Nothing to do here\n";
		return;
	} else {
		cout << "Yes\n";
		for (int i = 0; i < sz(ans); i++) {
			cout << ans[i] + 1 << ' ';
		}
		cout << '\n';
	}
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
