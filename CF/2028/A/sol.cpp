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
		int n, a, b;
		string s;
		cin >> n >> a >> b;
		cin >> s;
		int x = 0;
		int y = 0;
		bool isMeet = 0;
		rep(i,0,100) {
			if (isMeet == 1) break;
			rep(j,0,n) {
				if (x == a && y == b) {
					isMeet = 1;
					break;
				}
				if (s[j] == 'N') y++;
				if (s[j] == 'E') x++;
				if (s[j] == 'S') y--;
				if (s[j] == 'W') x--;
			}
		}
		if (isMeet) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
 

