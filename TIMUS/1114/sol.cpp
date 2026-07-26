#include "bits/stdc++.h"
 
using namespace std;
 
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
#define int long long
#define sz(x) (int)(x).size()
typedef vector<int> lnum;
const int di[4] = {0, 0, -1, 1};
const int dj[4] = {-1, 1, 0, 0};
 
 
 
void solve() {
	int N, A, B; cin >> N >> A >> B;
	auto C = [](int n, int k) {
		double res = 1;
		for (int i = 1; i <= k; i++) {
		    res = res * double(n - k  + i) / (double)i;
		}
		return (int)(res + 0.01);
	};
	const int base = 1000*1000*1000;
	auto mul = [](lnum a, lnum b) {
	    lnum c (a.size()+b.size());
	    for (size_t i=0; i<a.size(); ++i)
		for (int j=0, carry=0; j<(int)b.size() || carry; ++j) {
		    long long cur = c[i+j] + a[i] * 1ll * (j < (int)b.size() ? b[j] : 0) + carry;
		    c[i+j] = (int) (cur % base);
		    carry = (int) (cur / base);
		}
	    while (c.size() > 1 && c.back() == 0)
		c.pop_back();
	    return c;
	};
	auto lnumInput = [](string s) {
	    lnum a;
	    for (int i=(int)s.length(); i>0; i-=9)
		if (i < 9)
		    a.push_back (atoi (s.substr (0, i).c_str()));
		else
		    a.push_back (atoi (s.substr (i-9, 9).c_str()));
	    return a;
	};
	lnum CA = lnumInput(to_string(C(A + N, N)));
	lnum CB = lnumInput(to_string(C(B + N, N)));
	lnum ans = mul(CA, CB);
	string ansS = ans.empty() ? "0": to_string(ans.back());
	for (int i = sz(ans) - 2 ; i >= 0; i--) {
		string chunk = to_string(ans[i]);
		ansS += string(9 - sz(chunk), '0') + chunk;
	}
	cout << ansS << '\n';
}
 
int32_t main() {
    send help
 
    solve();
}
