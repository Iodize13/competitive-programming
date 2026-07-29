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
	int cnt = 0;
	stack<pair<int, int> > st;
	st.push({0, 1});
	while(!st.empty()) {
		auto [last, mask] = st.top();
		st.pop();
		if (mask == (1ll << N) - 1) {
		    cnt++;
		    continue;
		}
		for (int i = 1; i <= 2; i++) {
		    int nextR = 1ll << (i + last);
		    if (i + last < N && !(mask & nextR))  st.push({i + last, mask | nextR});
		    if (last - i >= 0) {
			int nextL= 1ll << (last - i);
			if (!(mask & nextL)) st.push({last - i, mask | nextL});
		    }
		}
	}
	cout << cnt << '\n';
}
 
int32_t main() {
    send help
 
    solve();
}
