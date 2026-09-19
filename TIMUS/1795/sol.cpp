// #pragma GCC optimize("O3,unroll-loops")
#include "bits/stdc++.h"

using namespace std;

#define int long long
#define sz(x) (int)(x).size()



void solve() {
	int M, N; cin >> M;
	map<string, int> mp;
	for (int i = 0; i < M; i++) {
		int x; cin >> x;
		string s; cin >> s >> s;
		mp[s] += x;
	}
	cin >> N;
	int res = 0;
	struct ct {
		string s;
		int x;
		int last = -1;
	};
	vector<ct> C;
	for (int i = 0; i < N; i++) {
		int x; cin >> x;
		string s; cin >> s >> s;
		C.push_back({s, x});
	}
	int idx = 0;
	while (idx < N) {
		auto [s, x, last] = C[idx];
		// cerr << "idx, s, x, last: " << idx << ' ' << s << ' ' << x << ' ' << last << endl;
		res++;
		if (mp[s] > 0) {
			if (mp[s] < x) {
				if (last != -1 && mp[s] == last) {
					mp[s] -= mp[s];
					idx++;
				} else {
					C[idx].last = mp[s];
					if (idx == N - 1) {
						break;
					}
					swap(C[idx], C[idx + 1]);
				}
			} else {
				mp[s] -= x;
				idx++;
			}
		} else {
			idx++;
		}
		// sleep(1);
	}
	cout << res << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

    solve();
}

