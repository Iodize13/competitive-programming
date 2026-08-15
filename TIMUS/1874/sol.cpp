#include "bits/stdc++.h"

using namespace std;

#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
#define int long long
#define sz(x) (int)(x).size()
const long double pi = atan(1) * 4;

void solve() {
	long double A, B; cin >> A >> B;
	cout << fixed << setprecision(7) << (A * A + B * B) / 4 + A * B / sqrt(2.l);
}

int32_t main() {
    send help

	solve();
}
