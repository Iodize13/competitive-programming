#include "bits/stdc++.h"

using namespace std;

#ifdef LOCAL
#define dbg(...) {fprintf(stderr, __VA_ARGS__);fputc('\n', stderr);fflush(stderr);}
#else
#define dbg(...) 42
#endif
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

void solve() {
    int M, D1, D2; cin >> M >> D1 >> D2;
    int sum = 0;
    for (int i = 0; i < D2; i++) {
	if (sum + (D1 * M - 1) / D2 + 1 <= D1 * M) {
	    cout << (D1 * M - 1) / D2 + 1 << ' ';
	    sum += (D1 * M - 1) / D2 + 1;
	} else {
	    cout << D1 * M - sum << ' ';
	    sum = D1 * M;
	}
    }
}

int32_t main() {
    send help

    solve();
}
