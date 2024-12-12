#include <bits/stdc++.h>
//#include <cstdio>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define pb push_back 
using ll=long long;
using pii=pair<int, int>;
using vi=vector<int>;

void DBG() {
	cerr << "]" << endl;
}
template<class H, class... T> void DBG(H h, T... t) {
	cerr << to_string(h);
	if(sizeof...(t))
		cerr << ", ";
	DBG(t...);
}
#ifdef LOCAL
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 42
#endif

int main() {
	ios::sync_with_stdio(false);
  	cin.tie(nullptr);
	int tt;
	cin >> tt;
	while(tt--) {
		int n, m, a, d;
		cin >> n >> m >> a >> d;
		int co = 0;
		rep(i,n,m+1) {
			if (i % a == 0 || i % (a + d) == 0 || i % (a + 2 * d) == 0
					|| i % (a + 3 * d) == 0 || i % (a + 4 * d) == 0) continue;
			co++;
		}
		cout << co << '\n';
	}
	return 0;
}
 

