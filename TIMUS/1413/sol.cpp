#include "bits/stdc++.h"
 
using namespace std;
 
#ifdef LOCAL
#define dbg(...) {fprintf(stderr, __VA_ARGS__);fputc('\n', stderr);fflush(stderr);}
#else
#define dbg(...) 42
#endif
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef vector<int> vi;
typedef pair<int, int> pii;
 
 
const bool TC = 0;
void solve() {
	string S; cin >> S;
	int N = sz(S);
	long double sq2 = sqrt(0.5l);
	vector<long double> di = {0, sq2, 1, sq2, 0, 0, 0, -sq2, -1, -sq2};
	vector<long double> dj = {0, -sq2, 0, sq2, -1, 0, 1, -sq2, 0, sq2};
	long double sti, stj;
	sti = stj = 0;
	for (int i = 0; i < N; i++) {
		if (S[i] == '0') {
			break;
		}
		sti += di[S[i] - '0'];
		stj += dj[S[i] - '0'];
	}
	cout << fixed << setprecision(15) << stj << ' ' << -sti << '\n';
}
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int tt = 1;
    if (TC) cin >> tt;
    while (tt--) solve();
}
