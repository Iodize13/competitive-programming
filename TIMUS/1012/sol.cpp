#include "bits/stdc++.h"
 
using namespace std;
 
#ifdef LOCAL
#include "debug.h"
#else
#define dbg(...) 42
#endif
#define int long long
#define sz(x) (int)(x).size()
const int di[4] = {0, 0, -1, 1};
const int dj[4] = {-1, 1, 0, 0};
 
 
 
void solve() {
    int N, K; cin >> N >> K;
    vector<string> dp(N + 1, "");
    dp[0] = to_string(K - 1);
    dp[1] = to_string((K - 1) * K);
    auto add = [&](string a, string b) {
	a = '0' + a;
	b = string(sz(a) - sz(b), '0') + b;
	string c = string(sz(a), '0');
    	for (int i = sz(a) - 1; i > 0 ;i--) {
		int rA = a[i] - '0';
		int rB = b[i] - '0';
		int rC = c[i] - '0';
		c[i] = (char)((rC + rA + rB) % 10 + '0');
		c[i - 1] = (char)(c[i - 1] + (rC + rA + rB) / 10);
	}
	int tmp = 0;
	while (c[tmp] == '0') {
		tmp++;
	}
	c.erase(0, tmp);
	return c;
    };
    auto mul = [&](string a, int b) {
	a = '0' + a;
	string c = string(sz(a), '0');
	for (int i = sz(a) - 1; i > 0; i--) {
		int rA = a[i] - '0';
		int rC = c[i] - '0';
		c[i] = (char)((rC + rA * b) % 10 + '0');
		c[i - 1] = (char)(c[i - 1] + (rC + rA * b) / 10);
	}
	int tmp = 0;
	while(c[tmp] == '0') {
		tmp++;
	}
	c.erase(0, tmp);
	return c;
    };
    for (int i = 2; i < N; i++) {
	string res =add(dp[i - 1], dp[i - 2]);
	dp[i] = mul(res, K - 1);
    }
    cout << dp[N - 1] << '\n';
}
 
int32_t main() {
    solve();
}
