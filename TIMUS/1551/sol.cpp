// #pragma GCC optimize("O3,unroll-loops")
#include "bits/stdc++.h"

using namespace std;

#define int long long
#define sz(x) (int)(x).size()



void solve() {
	int N; cin >> N;
	map<string, int> MP;
	bool ok = false;
	int mx = 0;
	for (int i = 0; i < (1<<N); i++) {
		string prefe; cin >> prefe >> prefe;
		MP[prefe]++;
		if (MP[prefe] > mx)
			mx = MP[prefe];
	}
	for (auto &[key,val]: MP) {
		if (val > (1 << (N - 1))) {
			cout << "0\n";
			return;
		} else if (val != 1) {
			ok = true;
		}
	}
	int j = 0;
	for (int i = (1 << N); i > 0; (i >>= 1), j++) {
		if (mx > i / 2)
			break;
	}
	cout << (ok ? j : N) << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

    solve();
}

