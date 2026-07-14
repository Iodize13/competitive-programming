#include "bits/stdc++.h"
 
using namespace std;
 
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
#define int long long
#define sz(x) (int)(x).size()
const int di[4] = {0, 0, -1, 1};
const int dj[4] = {-1, 1, 0, 0};
 
 
 
void solve() {
	string S; getline(cin, S);
	int N = sz(S);
	stack<pair<int, int> > st;
	st.push({0, N - 1});
	string A(N, '_');
	int i = 0;
	while (i < N) {
		auto [l, r] = st.top();
		st.pop();
		if (r < l) continue;
		int mid = (r + l) / 2;
		A[mid] = S[i];
		i++;
		st.push({mid + 1, r});
		st.push({l, mid - 1});
	}
	cout << A << '\n';
}
 
int32_t main() {
    send help
    solve();
}
