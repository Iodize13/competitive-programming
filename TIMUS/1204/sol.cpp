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
	int p, q, ans;
	for (int i = 2; i * i <= N; i++) if (N % i == 0) {
	    p = N / i;
	}
	for (int i = (((int)sqrt(N) + p - 1) / p) * p; i <= N; i+= p) {
	    if ((i * i) % N == i) {
		ans = i;
		break;
	    }
	}
	cout << "0 1 " << min(ans, N + 1 - ans) << ' ' << max(ans, N + 1 - ans) << '\n';


}
 
int32_t main() {
    send help
    int TT; cin >> TT;
    while (TT--) solve();
}
