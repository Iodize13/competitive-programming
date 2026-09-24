// #pragma GCC optimize("O3,unroll-loops")
#include "bits/stdc++.h"

using namespace std;

#define int long long
#define sz(x) (int)(x).size()


vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

void solve() {
	string S, T; cin >> S >> T;
	string combine = S + "$" + T;
	auto pi = prefix_function(combine);
	int N = sz(S);
	vector<string> ans;
	// for (int i = 0; i < sz(pi); i++) cerr << pi[i] << ' ';
	// cerr << '\n';
	int i = sz(combine) - 1;
	int sum = 0;
	while (pi[i] != 0) {
		ans.push_back(combine.substr(i - pi[i] + 1, pi[i]));
		sum += pi[i];
		i = i - pi[i];
		assert(i >= sz(S));
	}
	if (sum != sz(T)) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
		reverse(ans.begin(), ans.end());
		for (auto &x: ans) cout << x << ' ';
		cout << '\n';
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

    solve();
}

