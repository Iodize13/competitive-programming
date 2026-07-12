#include "bits/stdc++.h"
 
using namespace std;
 
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef vector<int> vi;
typedef pair<int, int> pii;
 
 
const bool TC = 0;
void solve() {
	int N; cin >> N;
	vector<array<int, 3> > A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i][0] >> A[i][1] >> A[i][2];
	}
	sort(A.begin(), A.end());
	int time = A[0][0];
	int ans = 0;
	for (int i = 0; i < N; i++) {
		time = max(time, A[i][0]);
		time += A[i][1];
		ans = max(ans,time - A[i][2]);
	}
	cout << ans << '\n';
}
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int tt = 1;
    if (TC) cin >> tt;
    while (tt--) solve();
}
