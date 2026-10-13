// #pragma GCC optimize("O3,unroll-loops")
#include "bits/stdc++.h"

using namespace std;

#define int long long
#define sz(x) (int)(x).size()



void solve() {
	int N, K; cin >> N >> K;
	int tmp = N;
	N %= K * 2;
	const int inf = (int)1e18;
	int center = N - (N - K) * 2;
	int R = N * N;
	// cerr << "N, K, R: " << N << ' ' << K << ' ' << R << endl;
	// cerr << "N > K: " << (N > K) <<'\n';
	// cerr << "R < (N - K) * (N - K): " << (N - K) * (N - K) << '\n';
	if (N >= K && (N - K) * (N - K) < R) {
		R = (N - K) * (N - K);
		cerr << "case 5" << endl;
	}
	if (N >= K && center * center < R) {
		R = center * center;
		cerr << "case 6" << endl;
	}
	// R = min({R, (N - K) * (N - K), center < 0 ? inf : center*center});
	// cerr << "r: " << R << '\n';
	// cerr << "center: " << center << '\n';
	cout << R << '\n';
	cout << (tmp * tmp - R) / K << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int tt; cin >> tt;
	while (tt--) solve();
}

