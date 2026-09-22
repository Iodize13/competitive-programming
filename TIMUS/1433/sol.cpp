// #pragma GCC optimize("O3,unroll-loops")
#include "bits/stdc++.h"

using namespace std;

#define int long long
#define sz(x) (int)(x).size()



void solve() {
	string S, T; cin >> S >> T;
	bool win = false;
	auto rot = [&] (auto &&self, string s, int idx) -> void {
		for (int i = 0; i < 4; i++) {
			char pillar = s[i];
			string wheel = s.substr(0, i) + s.substr(i + 1);
			for (int j = 0; j < 3; j++) {
				wheel = wheel.substr(1) + wheel.substr(0, 1);
				string cur = wheel.substr(0, i) + pillar + wheel.substr(i);
				// cerr << cur << '\n';
				if (idx == 0)self(self, cur, 1);
				if (cur == T) {
					win = true;
					break;
				}
			}
			// cerr << '\n';
		}
	};
	rot(rot, S, 0);
	cout << (win ? "equal": "different") << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

    solve();
}

