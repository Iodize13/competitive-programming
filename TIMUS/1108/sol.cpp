// #pragma GCC optimize("O3,unroll-loops")
#include "bits/stdc++.h"

using namespace std;

#define int long long
#define sz(x) (int)(x).size()



typedef vector<int> lnum;
const int base = 1000*1000*1000;

void trim(lnum& a) {
	while (sz(a) > 1 && a.back() == 0)
		a.pop_back();
}
void read(lnum& a) {
	string s; cin >> s;
	a.clear();
	for (int i = sz(s); i > 0; i -= 9)
		a.push_back(stoi(s.substr(max<int>(0, i-9), min<int>(9, i))));
	trim(a);
}
void write(const lnum& a) {
	string s = to_string(a.empty() ? 0 : a.back());
	char buf[10];
	for (int i = sz(a)-2; i >= 0; i--) {
		snprintf(buf, 10, "%09lld", a[i]);
		s += buf;
	}
	cout << s;
}
void add(lnum& a, const lnum& b) { // a += b
	int carry = 0;
	for (int i = 0; i < max(sz(a), sz(b)) || carry; i++) {
		if (i == sz(a)) a.push_back(0);
		a[i] += carry + (i < sz(b) ? b[i] : 0);
		carry = a[i] >= base;
		if (carry) a[i] -= base;
	}
}
void sub(lnum& a, const lnum& b) { // a -= b, assumes a >= b
	int carry = 0;
	for (int i = 0; i < sz(b) || carry; i++) {
		a[i] -= carry + (i < sz(b) ? b[i] : 0);
		carry = a[i] < 0;
		if (carry) a[i] += base;
	}
	trim(a);
}
void mulShort(lnum& a, int b) { // a *= b, 0 <= b < base
	int carry = 0;
	for (int i = 0; i < sz(a) || carry; i++) {
		if (i == sz(a)) a.push_back(0);
		int cur = carry + a[i] * b;
		carry = cur / base;
		a[i] = cur - carry * base; // avoid a second division
	}
	trim(a);
}
lnum mulLong(const lnum& a, const lnum& b) { // c = a * b
	lnum c(sz(a) + sz(b));
	for (int i = 0; i < sz(a); i++)
		for (int j = 0, carry = 0; j < sz(b) || carry; j++) {
			int cur = c[i+j] + a[i] * (j < sz(b) ? b[j] : 0) + carry;
			carry = cur / base;
			c[i+j] = cur - carry * base; // avoid a second division
		}
	trim(c);
	return c;
}


void solve() {
	int N; cin >> N;
	lnum mul = {1};
	for (int i = 0; i < N; i++) {
		lnum tmp = mul;
		add(tmp, {1});
		write(tmp);
		cout << '\n';
		mul = mulLong(mul, tmp);
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

    solve();
}

