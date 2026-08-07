#include "bits/stdc++.h"
#define int long long
#define sz(x) (int)(x).size()

using namespace std;


vector<short> prefixFunction(string s) {
    short n = (short)s.length();
    vector<short> pi(n);
    for (short i = 1; i < n; i++) {
        short j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

void solve() {
	string S; cin >> S;
	short N = (short)S.size();
	vector<vector<short> > pi;
	for (short i = 0; i < N - 1; i++) {
		// we can try reverse tomorrow
		pi.push_back(prefixFunction(S.substr(i)));
	}
	int cnt = 1;
	for (short i = 0; i < N - 1; i++) {
		short mx = 0;
		for (short j = 0; j <= i; j++) {
			// not sure about pi[j][i - j]
			mx = max(mx, pi[j][i + 1 - j]);
		}
		// i + 1 = length of string
		int cur = i + 2 - mx;
		// cerr << "cur: " << cur << '\n';
		cnt += cur;
	}
	// for (int i = 0; i < sz(pi); i++) {
	// 	for (int j = 0; j < sz(pi[i]); j++) {
	// 		cerr << pi[i][j] << " \n"[j == sz(pi[i]) - 1];
	// 	}
	// }
	cout << cnt << '\n';
}

int32_t main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(NULL);

	solve();
}
// actually don't need old one.
