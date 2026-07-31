#include "bits/stdc++.h"
 
using namespace std;
 
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
#define int long long
#define sz(x) (int)(x).size()
const int di[4] = {0, 0, -1, 1};
const int dj[4] = {-1, 1, 0, 0};
 
 
 
void solve() {
	int N; cin >> N;
	int quarter = 0;
	for (int i = 0; i < N; i++) {
		quarter += ceil(sqrt(N * N - i * i));
	}
	cout << quarter * 4 << '\n';
}
 
int32_t main() {
    send help
 
    solve();
}
