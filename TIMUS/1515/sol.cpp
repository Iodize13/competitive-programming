#include "bits/stdc++.h"

using namespace std;

#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
#define int long long
#define sz(x) (int)(x).size()



void solve() {
	int N; cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	int mx = 0;
	for (int i = 0; i < N; i++) {
		if (A[i] > mx + 1) break;
		mx += A[i];
	}
	cout << mx + 1;
}

int32_t main() {
    send help
    solve();
}
