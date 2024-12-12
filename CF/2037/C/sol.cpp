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
		int n;
		cin >> n;
		if (n < 5) cout << "-1";
		else {
			for (int i = 1; i <= n; i+=2) {
				if (i == 5) continue;
				else cout << i << ' ';
			}
			cout << "5 4 ";
			for (int i = 2; i <= n; i+=2) {
				if (i == 4) continue;
				cout << i << ' ';
			}
		}
		cout << '\n';
	}
	return 0;
}
 

