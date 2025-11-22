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
#define fi first
#define se second
#define int long long
#define ll long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef vector<int> vi;
typedef pair<int, int> pii;
void solve();
int case_num = 0;
const int di[4] = {0, 0, -1, 1};
const int dj[4] = {-1, 1, 0, 0};

int32_t main() {
    send help

    int tt;
    cin >> tt;
    while(tt--) {
        ++case_num;
        solve();
    }
}

vi topoSort(const vector<vi>& gr) {
	vi indeg(sz(gr)), q;
	for (auto& li : gr) for (int x : li) indeg[x]++;
	rep(i,0,sz(gr)) if (indeg[i] == 0) q.push_back(i);
	rep(j,0,sz(q)) for (int x : gr[q[j]])
		if (--indeg[x] == 0) q.push_back(x);
	return q;
}

void solve() {
    string s;
    int n;
    cin >> n;
    vector<vi> g(n);
    rep(i,0,n-1) {
        int u, v, x, y;
        cin >> u >> v >> x >> y;
        --u;
        --v;
        if (y > x) g[v].push_back(u);
        else g[u].push_back(v);
    }

    vi q = topoSort(g);
    vi a(n);
    for (int i = 0, j = n; i < n; i++, j--) {
        a[q[i]] = j;
    }

    rep(i,0,n) cout << a[i] << " \n"[i+1==n];
}

