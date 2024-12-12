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
	string s;
	cin >> s;
	bool isStart=0;
	string ans="";
	rep(i,0,(int)s.length()) {
		if(s[i]=='9' && !isStart) continue;
		else isStart=1;
		if(s[i]>='5') ans+=char('9'-s[i]+'0');
		else ans+=s[i];
	}
	if(ans.empty()) ans += s[s.length() - 1];
	cout << ans << '\n';
	return 0;
}

