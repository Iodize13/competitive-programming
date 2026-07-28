#include "bits/stdc++.h"
 
using namespace std;
 
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
#define int long long
#define sz(x) (int)(x).size()
typedef vector<int> lnum;
const int di[4] = {0, 0, -1, 1};
const int dj[4] = {-1, 1, 0, 0};
 
 
 
void solve() {
	string N, M; cin >> N >> M;
	if (sz(N) > sz(M)) swap(N, M);
	int szN = sz(N);
	int szM = sz(M);
	vector<vector<int> > dp(szN, vector<int>(szM, LLONG_MAX));
	vector<bool> visI(szN);
	vector<bool> visJ(szM);
	for (int i = 0; i < szN; i++) {
		for (int j = 0; j < szM; j++) {
			int notEq = (int)(N[i] != M[j]);
			if (i == 0 && j == 0) dp[i][j] = min(dp[i][j], notEq);
			if (i > 0 && j > 0) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + notEq);
			if (i > 0) dp[i][j] = min(dp[i][j], dp[i - 1][j] + (int)(notEq || visJ[j]));
			if (j > 0) dp[i][j] = min(dp[i][j], dp[i][j - 1] + (int)(notEq || visI[i]));
			visI[i] = visI[i] | !notEq;
			visJ[j] = visJ[j] | !notEq;
		}
	}

	cout << dp[szN - 1][szM - 1] << '\n';
}
 
int32_t main() {
    send help
 
    solve();
}

