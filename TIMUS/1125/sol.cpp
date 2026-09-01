#include "bits/stdc++.h"

using namespace std;

#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
#define int long long
#define sz(x) (int)(x).size()




void solve() {
	int M, N; cin >> M >> N;
	vector<vector<int> > A(M, vector<int>(N));
	vector<vector<int> > B(M, vector<int>(N));
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			char c; cin >> c;
			B[i][j] = c == 'W';
		}
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];
		}
	}
	auto valid = [&](int r, int c) {
		return r < M && r >= 0 && c < N && c >= 0;
	};
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = -M; k < M; k++) {
				for (int m = -N; m < N; m++) {
					// if (k != 0 && m != 0) {
						int t = sqrtl((long double)k * k + m * m);
						if (t * t == k * k + m * m) {
							int nr = i + k;
							int nc = j + m;
							if (valid(nr, nc)) B[nr][nc] += A[i][j];
						}
					// }
				}
			}
		}
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cout << (B[i][j] % 2 ? 'W' : 'B');
		}
		cout << '\n';
	}
}

int32_t main() {
    send help

	solve();
}
