#include<bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = (ll)1e9 + 7;

void runcase() {
	ll a, b;
	ll ans=  1;
	cin >> a >> b;
	// cerr << "a: " << a << ", b:" << ' ' << b << '\n';
	map<ll, ll> ma;
	ma[0] = 1;
	ma[1] = a;
	for (ll i = 2; i <= 1e9 + 1 ; i *= 2) {
		a = (a * a) % MOD;
		ma[i] = a;
	}

	// cerr << "dbg: ";
	// for (auto [key, val]: ma) cerr << key << ' ' << val << '\n';

	int j = 1;
	
	if (a == 0 && b != 0) {
		cout << 0 << '\n';
		return;
	}
	while (b){
		ans = (ans * (max(1LL, (b & 1) * ma[j]) % MOD)) % MOD;
		// cerr << "dbg: " << (b & 1) << ' ' << ma[j] << '\n';;
		// cout << (b & 1);
		b>>=1;	
		j*=2;
	}
	cout << ans << '\n';
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		runcase();
	}
	return 0;
}
