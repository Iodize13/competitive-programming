#include "bits/stdc++.h"
 
using namespace std;
 
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
#define int long long
#define sz(x) (int)(x).size()
 
 
 
void solve() {
	int N; cin >> N;
	if (N <= 2) {
		cout << N << '\n';
		for (int i = 0; i < N; i++) cout << 1 << ' ';
		cout << '\n';
		return;
	}
	if (N == 4) {
		cout << "5\n2 3 4 2 3\n";
		return;
	}
	if (N % 2 == 0) {
		cout << (N - 2) * 2 + 1 << '\n';
		for (int i = 2; i < N; i++) cout << i << ' ';
		cout << N - 1 << ' ';
		for (int i = 2; i < N; i++) cout << i << ' ';
	} else {
		cout << (N - 2) * 2 << '\n';
		for (int i = N - 1; i >= 2; i--) cout << i << ' ';
		for (int i = N - 1; i >= 2; i--) cout << i << ' ';
	}
	cout << '\n';
}
 
int32_t main() {
    send help
 
    solve();
}
