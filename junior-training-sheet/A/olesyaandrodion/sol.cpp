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
	int n, t;
	cin >> n >> t;
	if (t == 10) {
		if (n == 1) {
			cout << "-1\n";
			return 0;
		}
		else cout << '1';
	}
	else cout << t;
	rep(i,0,n-1) {
		cout << '0';
	}
	cout << '\n';
	return 0;
}
 

