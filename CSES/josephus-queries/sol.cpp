#include<bits/stdc++.h>

using namespace std;

using ll = long long;

void runcase() {
	ll n, q;
	cin >> n >> q;
	ll j = 0;
	ll k = 2;
	ll i = 0;
	// int a[(int)1e9];
	while (i < q) {
		j += k;
		if (j > n) {
			j %= n;
			if (j == 0) j += n;
			k *= 2;
		}
		i++;
	}
	cout << j << '\n';
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		runcase();
	}
	return 0;
}

// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
// 1 3 5 7 9 11 13 15
// 3 7 11 15
// 7 15
