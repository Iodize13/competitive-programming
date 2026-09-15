// #pragma GCC optimize("O3,unroll-loops")
#include "bits/stdc++.h"

using namespace std;

#define int long long
#define sz(x) (int)(x).size()



void solve() {
	int N; cin >> N;
	++N;
	int M;
	vector<vector<vector<int> > > bit(N, vector<vector<int> >(N, vector<int>(N)));
	auto sum = [&](int x, int y, int z) {
		int ret = 0;
		for (int i = x + 1; i > 0; i -= i & -i) {
			for (int j = y + 1; j > 0; j -= j & -j) {
				for (int k = z + 1; k > 0; k -= k & -k) {
					ret += bit[i][j][k];
					// cerr << "xyz: " << x << y << z << endl;
					// cerr << "2,2,2: " << bit[2][2][2] << endl;
					// cerr << "z: " << z << '\n';
					// cerr << z - (z & -z) << '\n';
				}
			}
		}
		return ret;
	};
	auto rangeSum = [&](int x1, int y1, int z1, int x2, int y2, int z2) {
		int ret= sum(x2,y2, z2)
			- (sum(x1 - 1,y2,z2) + sum(x2,y1 - 1, z2) + sum(x2, y2, z1 - 1))
			+ sum(x1 - 1, y1 - 1, z2) + sum(x2, y1 - 1, z1 - 1) + sum(x1 - 1, y2, z1 - 1)
			- sum(x1 - 1, y1 - 1, z1 - 1);
		return ret;
	};
	while (cin >> M) {
		if (M == 3) return;
		if (M == 1) {
			int X, Y, Z, K; cin >> X >> Y >> Z >> K;
			int cur = rangeSum(X,Y,Z,X,Y,Z);
			for (int i = X + 1; i < N; i += i & -i) {
				for (int j = Y + 1; j < N; j += j & -j) {
					for (int k = Z + 1; k < N; k += k & -k) {
						bit[i][j][k] += K;
					}	
				}
			}
			// for (int i = 0; i < N; i++) {
			// 	for (int j = 0; j < N; j++) {
			// 		for (int k = 0; k < N; k++) {
			// 			cerr << bit[i][j][k];
			// 		}
			// 		cerr << '\n';
			// 	}
			// 	cerr << '\n';
			// }
			// cerr << "2, 2, 2: " << bit[2][2][2] << endl;
		} else {
			int X1, X2, Y1, Y2, Z1, Z2; cin >> X1 >> Y1 >> Z1 >> X2 >> Y2 >> Z2;
			// consider 0 // >=
			// cerr << "X2, Y2, Z2: " << X2 << ' ' << Y2 << ' ' << Z2 << endl;
			cout << rangeSum(X1, Y1, Z1, X2, Y2, Z2) << '\n';
			//cerr << "debug: " << sum(X2, Y2, Z2) << '\n';
		}
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

    solve();
}

