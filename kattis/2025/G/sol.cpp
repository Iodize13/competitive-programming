#include<bits/stdc++.h>

using namespace std;

using ll = long long;

vector<ll> c;

void runcase() {
	stack<ll> st;
	ll x;
	cin >> x;
	ll a[13];
	for (int i = 0 ; i < 12; i++) 
		cin >> a[i];

	ll tmp = 0;
	ll ans = 0;
	st.push(0);
	for (int i = 0 ; i < 12; i++) {
		cerr << "i: " << i <<", st.top(): " << st.top() << '\n';
		if (a[i] <= st.top()) {
				while (!st.empty() && st.top() > a[i]) {
				st.pop();
				++ans;
				}
		}
		if (a[i] > st.top()) {
			st.push(a[i]);
			// cerr << "i: " << i << '\n';
		}
	}
	cout << x << ' ' << ans <<'\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	c.clear();
	c.emplace_back(0);
	ll testcase; cin >> testcase;
	while(testcase--) {
		runcase();
	}
	return 0;
}
