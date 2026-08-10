#include "bits/stdc++.h"

using namespace std;

#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
#define int long long
#define sz(x) (int)(x).size()

struct Node {
	vector<pair<int, int> > p = {{-1, -1}, {-1, -1}};
	bool isMatch = false;
	bool isEmpty() {
		return p == vector<pair<int, int> >{{-1, -1}, {-1, -1}};
	}
};

void solve() {
    string S; cin >> S;
    if (S == "") {
    	cout << "\n";
	return;
    }
    // bool ch = true;
    vector<pair<string, int> > A;
    auto ok = [](char a, char b) {
	return (a == '(' && b == ')') || (a == '[' && b == ']');
    };
    auto reversed = [](char x) {
	if (x == '(') return ")";
	else if (x == ')') return "(";
	else if (x == ']') return "[";
	else return "]";
    };
    // for (int i = sz(S) - 2; i >= 0;) {
    //     if (ok(S[i], S[i + 1])) {
    //         int j = 0;
    //         while (i - j >= 0 && i + j + 1< sz(S) && ok(S[i - j], S[i + j + 1])) {
    //     	j++;
    //         }
    //         j--;
    //         A.push_back({S.substr(i - j, 2 * j + 2), i - j});
    //         // S.erase(i - j, 2 * j + 2);
    //         i = i - j - 1;
    //     } else i--;
    // }
    // for (auto &[fi, se]: A) {
    //     S.erase(se, sz(fi));
    //     // cerr << fi << ' ' << se << '\n';
    // }
    int N = sz(S);
    vector<vector<int> > dp(N, vector<int>(N, 0));
    vector<bool> add(N, true);
    vector<vector<Node > > par(N, vector<Node>(N));
    for (int i = 0; i < N; i++) {
	dp[i][i] = 1;
    }
    for (int len = 1; len < N; len++) {
	for (int i = 0; i < N - len; i++) {
	    if (len == 1) dp[i][i + len] = 0;
	    else {
		dp[i][i + len] = dp[i + 1][i + len - 1];
	    }
	    bool isMatch = true;
	    if (!ok(S[i], S[i + len])) {
		dp[i][i + len] += 2;
		isMatch = false;
	    }
	    par[i][i + len].p = {{i + 1, i + len - 1}, {-1, -1}};
	    par[i][i + len].isMatch = isMatch;
	    for (int k = i; k < i + len; k++) {
		if (dp[i][k] + dp[k + 1][i + len] < dp[i][i + len]) {
			dp[i][i + len] = dp[i][k] + dp[k + 1][i + len];
			par[i][i + len].p = {{i, k}, {k + 1, i + len}};
			par[i][i + len].isMatch = false;
		}
	    }
	    // int mn = min({dp[i][i + len], dp[i + 1][i + len] + 1, dp[i][i + len - 1] + 1});
	    // if (dp[i + 1][i + len] + 1 == mn) {
	    //     par[i][i + len].p = {{i + 1, i + len}, {-1, -1}};
	    // } else if (dp[i][i + len - 1] + 1 == mn) {
	    //     par[i][i + len].p = {{i, i + len - 1}, {-1, -1}};
	    // }
	    // dp[i][i + len] = mn;
	    // cerr << dp[i][i + len] << ' ';
	}
	// cerr << '\n';
    }
    int ti = 0, tj = N - 1;
    stack<pair<int, int> > st;
    st.push({ti, tj});
    while (!st.empty()) {
	auto [ci, cj] = st.top();
	st.pop();
	// cerr << ci << ' ' << cj << ' ' << '\n';
	if (par[ci][cj].p[0] != make_pair(-1ll, -1ll)) st.push(par[ci][cj].p[0]);
	if (par[ci][cj].p[1] != make_pair(-1ll, -1ll)) st.push(par[ci][cj].p[1]);
	if (par[ci][cj].isMatch) {
	    add[ci] = add[cj] = false;
	}
    }
    // for (int i = 0; i < N; i++) cerr << add[i];
    // cerr << '\n';
    string ans = "";
    int sum = 0;
    for (int i = 0; i < N; i++) {
	string tmp = reversed(S[i]);
	// string old = "";
	// while (!A.empty() && A.back().second == i + sum) {
	//     // cerr << "enter\n";
	//     old += A.back().first;
	//     A.pop_back();
	//     sum += sz(old);
	// }
	// ans += old;
	if (S[i] == '(' || S[i] == '[') {
	    ans += S[i] + (add[i] ? tmp : "");
	} else {
	    ans += (add[i] ? tmp : "") + S[i];
	}
    }
    // reverse(A.begin(), A.end());
    // for (auto [fi, se]: A) ans += fi;
    cout << ans << '\n';
    // cerr << sz(ans) << '\n';
    // cerr << dp[0][N - 1] << '\n';
}

int32_t main() {
    send help

	solve();
}
// [(((]))) // save 2 ] if choose to fill
// [(] // here ew should choose to fill (
// just decide wheter to close now or the cost.
// not that easy tho. i.e. (((]]))
