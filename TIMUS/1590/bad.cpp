// #pragma GCC optimize("O3,unroll-loops")
#include "bits/stdc++.h"

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define dbg(...) 42
#endif
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
#define fi first
#define se second
#define int long long
#define ll long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef vector<int> vi;
typedef pair<int, int> pii;
void solve();
const int di[4] = {0, 0, -1, 1};
const int dj[4] = {-1, 1, 0, 0};
const int inf = (int)2e18 + 5;

int32_t main() {
    send help

	solve();
}

void solve() {
	string S; cin >> S;
	int N = sz(S);
	set<string> se;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < N && j + i <= N; j++) {
		    se.insert(S.substr(j, i));
		}
	}
	cout << sz(se) << '\n';
}

