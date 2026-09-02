#include "bits/stdc++.h"

using namespace std;

#define send                                                                   \
{                                                                            \
	ios_base::sync_with_stdio(false);                                          \
}
#define help                                                                   \
{                                                                            \
	cin.tie(NULL);                                                             \
}
#define int long long
#define sz(x) (int)(x).size()


const int inf = (int) 1e9;
void solve(string S) {
	int N = sz(S);
	int K;
	cin >> K;
	map<string, string> M;
	vector<int> az('z' + 1);
	az['i'] = az['j'] = '1';
	az['a'] = az['b'] = az['c'] = '2';
	az['d'] = az['e'] = az['f'] = '3';
	az['g'] = az['h'] = '4';
	az['k'] = az['l'] = '5';
	az['m'] = az['n'] = '6';
	az['p'] = az['r'] = az['s'] = '7';
	az['t'] = az['u'] = az['v'] = '8';
	az['w'] = az['x'] = az['y'] = '9';
	az['o'] = az['q'] = az['z'] = '0';
	for (int i = 0; i < K; i++) {
		string T;
		cin >> T;
		string newS = "";
		for (int j = 0; j < sz(T); j++) {
			newS += az[(int)T[j]];
		}
		M[newS] = T;
	}
	vector<int> dp(N + 1, inf);
	vector<string> path(N + 1);
	dp[0] = 0;
	path[0] = "-1";
	for (int i = 1; i < N + 1; i++) {
		for (int j = 0; j <= i; j++) {
			string tmp = S.substr(j, i - j);
			// cerr << tmp << '\n';
			if (M.count(tmp) == 1) {
				// cerr << "case: 5\n";
				if (dp[j] + 1 < dp[i]) {
					// cerr << "case: 6\n";
					dp[i] = dp[j] + 1;
					path[i] = M[tmp];
				}
			}
		}
	}
	if (dp[N] != inf) {
		int cur = N;
		vector<string> ans;
		while (cur != 0) {
			ans.push_back(path[cur]);
			cur -= sz(path[cur]);
		}
		for (int i = sz(ans) - 1; i >= 0; i--) cout << ans[i] << " \n"[i == 0];
	} else {
		cout << "No solution.\n";
	}
}

int32_t main() {
	send help

		string S;

	while (cin >> S) {
		if (S == "-1") {
			return 0;
		}

		solve(S);
	}
}

// wrong case 0000000 00 00 00 00 00 00 00
// instead of 00 0000000000000000000000000
