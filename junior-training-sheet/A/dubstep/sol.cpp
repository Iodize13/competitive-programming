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
	s += "abc";
	string ans = "";
	rep(i,0,s.length()-3) {
		if (s[i] == 'W' && s[i+1] == 'U' && s[i+2] == 'B') {
			i += 2;
			if (/*lastWub == 1 ||  */ans[ans.length()-1] == ' ' || ans == "") {
			} else {
				ans += ' ';
			}
			//lastWub = 1;
		} else {
			ans += s[i];
			// if last word was wub or last of ans is ' ' then skip
		}
	}
	cout << ans << '\n';
	return 0;
}
 

