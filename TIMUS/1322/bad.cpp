// #pragma GCC optimize("O3,unroll-loops")
#include "bits/stdc++.h"
 
using namespace std;
 
#ifdef LOCAL
#include "debug.h"
#else
#define dbg(...) 42
#endif
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
#define f first
#define s second
// #define int long long
#define ll long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef vector<int> vi;
typedef pair<int, int> pii;
const int di[4] = {0, 0, -1, 1};
const int dj[4] = {-1, 1, 0, 0};
 
 
 
const bool TC = 0;
void solve() {
	int K; cin >> K;
	string S; cin >> S;
	int N = (int)S.size();
	string T = S;
	sort(T.begin(), T.end());
	cerr << T << '\n';
	vector<vector<int> > adj('z' + 9);
	map<char, int> M;
	for (int i = 0; i < N; i++) {
		adj[S[i]].push_back(T[i]);
		M[S[i]]++;
	}
	for (int i = 0; i < N; i++) {
		sort(adj[i].begin(), adj[i].end());
	}
	vector<vector<bool> > vis('z' + 9);
	for (int i = 0; i < (int)vis.size(); i++) {
		vis[i].resize((int)adj[i].size());
	}
	stack<array<int,3> > st;
	int cnt = 0;
	string path(N, '0');
	// for (int i = N - 1; i >= 0; i--) {
	for (int i = 0; i < N; i++) {
		st.push({T[i], 0, 1});
		M[T[i]]--;
		path[0] = T[i];
		cerr << "0 " << T[i] << endl;
		while (!st.empty()) {
			cerr << "what 0 " << endl;
			auto [cur, fr, len] = st.top();
			if (len == N) {
				cerr << "what" << endl;
				cerr << path << endl;
				cnt++;
				st.pop();
				if (!st.empty()) {
					M[(char)cur]++;
					vis[st.top()[1]][cur] = false;
					continue;
				}
				break;
			}
			cerr << "case 0" << endl;
			if (fr == (int)adj[cur].size()) {
				st.pop();
				M[(char)cur]++;
				// is this next line correct?
				cerr << "before 2" << endl;
				vis[st.top()[1]][cur] = false;
				cerr << "after 2" << endl;
				st.push({st.top()[0], st.top()[1] + 1, st.top()[2]});
				continue;
			}
			// cerr << "before" << endl;
			cerr << len << ' ' << (char)cur << ' ' << fr << endl;
			cerr << "adj[cur][fr]]: " << (char)adj[cur][fr] << ' ' << M[(char)adj[cur][fr]] << ", bool: " << (M[(char)adj[cur][fr]] > 0) << ' ' << !vis[cur][fr] << '\n';
			if (M[(char)adj[cur][fr]] > 0 && !vis[cur][fr]) {
				vis[cur][fr] = true;
				M[(char)adj[cur][fr]]--;
				path[len] = (char)adj[cur][fr];
				st.push({adj[cur][fr], 0,len + 1});
				cerr << "done" << endl;
			} else {
				st.pop();
				st.push({cur, fr + 1, len});
			}
			// cerr << "after" << endl;
		}
		M[T[i]]++;
		if (cnt == K) {
			cout << path << '\n';
			break;
		}
	}
}
 
int32_t main() {
    send help
 
    int tt = 1;
    if (TC) cin >> tt;
    while (tt--) solve();
}
