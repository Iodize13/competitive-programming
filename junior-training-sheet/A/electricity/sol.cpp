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

int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isLeap(int y) {
	return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
}

int main() {
	ios::sync_with_stdio(false);
  	cin.tie(nullptr);
	int n;
	while(cin >> n && n) {
		int d1, m1, y1, c1,
			d2, m2, y2, c2;
		int ans = 0;
		int sum = 0;
		cin >> d1 >> m1 >> y1 >> c1;
		rep(i,0,n-1) {
			cin >> d2 >> m2 >> y2 >> c2;
			if (y1 == y2) {
				if (m1 == m2) {
					if (d2 - d1 == 1) {
						ans++;
						sum += c2 - c1;	
					}
				} else if (m2 - m1 == 1) {
					if (m1 == 2) {
						if(isLeap(y1) && d1 == 29 &&
								d2 == 1) {
							ans++;
							sum += c2 - c1;	
						} else if (!isLeap(y1) && d1 == 28 && d2 == 1) {
							ans++;
							sum += c2 - c1;
						}
					}
					else if (d1 == month[m1] && d2 == 1) {
						ans++;
						sum += c2 - c1;	
					}
				}
			} else if (y2 - y1 == 1) {
				if (m1 == 12 && m2 == 1 &&
						d1 == 31 && d2 == 1) {
					ans++;
					sum += c2 - c1;
				}
			}
			d1 = d2;
			m1 = m2;
			y1 = y2;
			c1 = c2;
		}
		cout << ans << ' ' << sum << '\n';
	}
	return 0;
}
 

