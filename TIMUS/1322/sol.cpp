#include "bits/stdc++.h"
 
using namespace std;
 
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
#define int long long
#define sz(x) (int)(x).size()
const int di[4] = {0, 0, -1, 1};
const int dj[4] = {-1, 1, 0, 0};
 
 
 
void solve() {
	int ini; cin >> ini;
	string S; cin >> S;
	int N = sz(S);
	vector<pair<char, int> > A;
	for (int i = 0; i < N; i++) A.emplace_back(S[i], i);
	sort(A.begin(), A.end());
	string ans = "";
	for (int i = 0, cur = ini - 1; i < N; i++) {
		ans += A[cur].first;
		cur = A[cur].second;
	}
	cout << ans << '\n';
}
 
int32_t main() {
    send help
 
    solve();
}
