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
	while (tt--) {
		int k;
		cin >> k;
		map<int, int> a;
		bool alreadyAns = 0;
		rep(i,0,k) {
			int x;
			cin >> x;
			if (alreadyAns) continue;
			if ((k-2) % x == 0 && a[((k-2)/x)]) {
				cout << x << ' ' << (k-2)/x << '\n';	
				alreadyAns = 1;
			}
			a[x]++;
		}
	}
	return 0;
}
 

