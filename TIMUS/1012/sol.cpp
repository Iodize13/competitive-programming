#include "bits/stdc++.h"
 
using namespace std;
 
#define int long long
#define sz(x) (int)(x).size()
const int di[4] = {0, 0, -1, 1};
const int dj[4] = {-1, 1, 0, 0};
 
 
 
void solve() {
    int N, K; cin >> N >> K;
    vector<vector<int> > dp(N + 1);
    dp[0] = {K - 1};
    dp[1] = {(K - 1) * K};
    const int base = 1000*1000*1000;
    auto add = [](vector<int> a, vector<int> b) {
	int carry = 0;
	for (size_t i = 0; i < max(a.size(), b.size()) || carry; i++) {
	    if (i == a.size())
		a.push_back(0);
	    a[i] += carry + (i < b.size() ? b[i] : 0);
	    carry = a[i] >= base;
	    if (carry) a[i] -= base;
	}
	return a;
    };
    auto mul = [](vector<int> a, int b) {
	int carry = 0;
	for (size_t i = 0; i < a.size() || carry; i++) {
	    if (i == a.size())
		a.push_back(0);
	    int cur = carry + a[i] * b;
	    carry = (int)(cur / base);
	    a[i] = cur - carry * base;
	}
	while (sz(a) > 1 && a.back() == 0) 
	    a.pop_back();
	return a;
    };
    for (int i = 2; i < N; i++) {
	vector<int> res =add(dp[i - 1], dp[i - 2]);
	dp[i] = mul(res, K - 1);
    }
    vector<int> A = dp[N - 1];
    string result = to_string(A.empty() ? 0: A.back());
    for (int i = sz(A) - 2; i >= 0; i--) {
	string chuck = to_string(A[i]);
	chuck = string(9 - sz(chuck), '0') + chuck;
	result += chuck;
    }
    cout << result << '\n';
}
 
int32_t main() {
    solve();
}
