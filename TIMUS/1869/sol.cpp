#include "bits/stdc++.h"
#include "assert.h"

using namespace std;

#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
#define int long long
#define sz(x) (int)(x).size()

void solve() {
	int N; cin >> N;
	vector<vector<int> > A(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];
		}
	}
	int sum = 0;
	int mx = 0;
	for (int s = 0; s < N; s++) {
		for (int j = 0; j < s; j++) {
			sum -= A[j][s];
		}
		for (int j = s + 1; j < N; j++) {
			sum += A[s][j];
		}
		mx = max(mx, sum);
	}
	assert(sum == 0);
	for (int s = N - 1; s >= 0;  s--) {
		for (int j = s; j < N; j++) {
			sum -= A[j][s];
		}
		for (int j = 0; j < s; j++) {
			sum += A[s][j];
		}
		mx = max(mx, sum);
	}
	cout << (mx + 36 - 1) / 36 << '\n';
}

int32_t main() {
	send help
		solve();
}
