#include "bits/stdc++.h"
#define int long long
#define sz(x) (int)(x).size()

using namespace std;

void solve() {
	int A, B, C; cin >> A >> B >> C;
	cout << min(abs(A - B), min(abs(B - C), abs(A - C))) << '\n';
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int TT; cin >> TT;
	while (TT--) solve();
}
