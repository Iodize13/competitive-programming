#include "bits/stdc++.h"
#define int long long
#define sz(x) (int)(x).size()

using namespace std;

void solve() {
	string S;
	int N; cin >> N >> S;
	int idx = 0;
	int cnt = 1;
	int ans = 1;
	bool ok = false;
	for (int i = 0; i < N - 1; i++) {
		if (S[i] != S[i + 1]) {
			if (cnt == 1) {
			    // cerr << S[i] << ' ' << S[i + 1] << '\n';
			    if (i != 0 && S[i - 1] == S[i + 1]) ok = true;
			    idx = i;
			}
			cnt = 1;
			ans++;
		} else cnt++;
	}
	if (idx != 0) {
	// cerr << "idx: " << idx << '\n';
	    cout << ans - 1 - ok << '\n';
	} else cout << ans << '\n';
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int TT; cin >> TT;
	while (TT--) solve();
}
