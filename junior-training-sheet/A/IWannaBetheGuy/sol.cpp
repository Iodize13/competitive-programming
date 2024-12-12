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

// void DBG() {
// 	cerr << "]" << endl;
// }
// template<class H, class... T> void DBG(H h, T... t) {
// 	cerr << to_string(h);
// 	if(sizeof...(t))
// 		cerr << ", ";
// 	DBG(t...);
// }
// #ifdef LOCAL
// #define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
// #else
// #define dbg(...) 42
// #endif

int main() {
	ios::sync_with_stdio(false);
  	cin.tie(nullptr);
	int n;
	cin >> n;
	int p, q;
	cin >> p;
	bool a[n] = {0};
	int x;
	rep(i,0,p) {
		cin >> x;
		a[x-1] = 1;
	}
	cin >> q;
	rep(j,0,q) {
		cin >> x;
		a[x-1] = 1;
	}

	rep(i,0,n) {
		if(a[i]==0) {
			cout << "Oh, my keyboard!\n";
			return 0;
		}
	}
	cout << "I become the guy.\n";
	return 0;
}
 

