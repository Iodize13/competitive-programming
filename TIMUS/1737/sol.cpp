// #pragma GCC optimize("O3,unroll-loops")
#include "bits/stdc++.h"

using namespace std;

#define int long long
#define sz(x) (int)(x).size()



void solve() {
	int N; cin >> N;
	if (N == 1) {
		cout << "a\nb\nc\n";
	} else if (N == 2) {
		cout << "ab\nac\nba\nbc\nca\ncb\n";
	} else {
		if (N * 6 > 100000) {
			cout << "TOO LONG\n";
		} else {
			vector<string> path = { "abc",
									"acb",
									"bac",
									"bca",
									"cab",
									"cba" };
			for (int i = 0; i < 6; i++) {
				for (int j = 0; j < N / 3; j++) {
					cout << path[i];
				}
				cout << path[i].substr(0, N % 3) << '\n';
			}
		}
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

    solve();
}

