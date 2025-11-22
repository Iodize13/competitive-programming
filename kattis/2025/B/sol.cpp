#include<bits/stdc++.h>

using namespace std;

using ll = long long;

vector<ll> c;

void runcase() {
	ll a, b;
	cin >> a >> b;
	ll ans = 0;
	for (auto X: c) {
		ll mnX = X - min(b, X);
		cerr << "mnX: " << mnX << ", X: " << X << '\n';
		if (mnX > a) break;
		ans += min(a, X)- mnX + 1;
		cerr << "tmp: " << a - mnX + 1 << '\n';
		cerr << "ans: " << ans << '\n';
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	c.clear();
	c.emplace_back(0);
	for (int i = 0; c.back() + (ll)pow(2, i) <= (ll)2e8 + 1 ; i++) {
		cerr << c.back() << ' ';
		c.emplace_back(c.back() + (ll)pow(2, i));
	}
	cerr << '\n';
	ll testcase; cin >> testcase;
	while(testcase--) {
		runcase();
	}
	return 0;
}

// 0 1 3 7

// trace testcase first dumbass. it icpc not CF.
