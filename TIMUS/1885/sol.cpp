#include "bits/stdc++.h"
 
using namespace std;
 
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
#define int long long
#define sz(x) (int)(x).size()
const int di[4] = {0, 0, -1, 1};
const int dj[4] = {-1, 1, 0, 0};
 
 
 
void solve() {
	long double T;
	int H, V, X; cin >> H >> T >> V >> X;
	long double C = V * T - H;
	long double X0 = C / (V - X);
	cout << fixed << setprecision(6) << max(0.l, T - X0) << ' ' << min(T, (long double)H / X) << '\n';
}
 
int32_t main() {
    send help
 
    solve();
}
