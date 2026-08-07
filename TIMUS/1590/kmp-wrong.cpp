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
	int ans = (1 + N) * N / 2ll;
	vector<vector<bool> > vis(N, vector<bool>(N, false));
	for (int i = 0; i < N; i++) {
		vector<int> lps(N, 0);
		int len = 0;
		for (int j = i + 1; j < N; j++) {
			// S[i + len] = front
			if (S[j] == S[i + len]) {
			    if (vis[i][len]) {
				cerr << "case 0, i, j: " << i << ", " << j << '\n';
				cerr << "len: " << len << '\n';
			    }
			    lps[j] = len;
			    if (!vis[i][len]) {
				cerr << "case 1, i, j: " << i << ", " << j << '\n';
				ans--;
			    }
			    vis[j-len][len] = true;
			    len++;
			} else if (S[j] != S[i + len] && len == 0) {
			    len = 0;
			    lps[j] = len;

			} else {
			    // cerr << "case 3, i, j: " << i << ", " << j << '\n';
			    len = S[j] == S[i];
			    lps[j] = len;
			    if (!vis[i][len] && lps[j]) {
				cerr << "case 2, i, j: " << i << ", " << j << '\n';
				ans --;
				vis[j][0] = true;
			    }
			}
		}
		// cerr << S[i] - 'a' << endl;
	}
	cout << ans << '\n';
}

// a
// aa
// aab, -> check if b, ab already exist
// a:a,
// b:aa, ab:aa
// a:aab, ba:aab, aba:aab

