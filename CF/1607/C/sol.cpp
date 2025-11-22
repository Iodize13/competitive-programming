#include <bits/stdc++.h>
//#include <cstdio>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define eb emplace_back
using ll=long long;
using pii=pair<int, int>;
using vi=vector<int>;
using ld=long double;

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

ll n, m, q, l, y ,z;
string s, t;

const char nl = '\n';
ll a[(int)1e6+ 9];
ll c[(int)1e6+ 9];

void runcase(){
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if (n == 1) {
		cout << a[0] << '\n';
		return;
	}
	sort(a, a+ n);
	ll cur = a[0];
	ll ans = cur;
	ll prev = a[1];
	for (int i = 1; i < n; i++) {
		cur = a[i] - prev;
		prev += cur;
		ans = max(ans, cur);
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int testcase(1); cin>>testcase;
	while(testcase--) runcase();
	return 0;
}



