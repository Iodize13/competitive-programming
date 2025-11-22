#include<bits/stdc++.h>

using namespace std;

long long n;

void runcase() {
	long long k;
	cin >> n >> k;
	string s;
	cin >> s;
	long long cnt = 0;
	for (int i = 0; i< n; i++) {
		if (s[i] == '1') ++cnt;
	}

	bool ok = false;
	if (cnt <= k) {
		ok = true;	
	}
	if (s.length() <= (2 * (k - 1) + 1)) ok = true;
	cout << (ok ? "Alice" : "Bob") << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while(t--) {
		runcase();
	}
}

