#include "bits/stdc++.h"

using namespace std;

#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
#define int long long
#define sz(x) (int)(x).size()



void solve() {
	int N; cin >> N;
	struct point {
		int x, y, r;
		bool inside(int i, int j) {
			return (i - x) * (i - x) + (j - y) * (j - y) <= r * r;
		}
	};
	vector<point> A;
	for (int i = 0; i < N; i++) {
		long double x, y, r; cin >> x >> y >> r;
		A.push_back({x * 200, y * 200, r * 200});
	}
	long double cnt = 0;
	for (int i = 0; i < 200; i++) {
		for (int j = 0; j < 200; j++) {
			for (int k = 0; k < N; k++) {
				if (A[k].inside(i, j)) {
					cnt++;
					break;
				}
			}
		}
	}
	cout << fixed << setprecision(1) << (cnt / 200 / 200 * 100) << '\n';
}

int32_t main() {
    send help

    solve();
}
