#include<bits/stdc++.h>

using namespace std;
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
#define rep(i, a, b) for(int i = a; i < (b); ++i)


int tt = 1;

int n, m, k;
string s;

bool dfs(int a, int L, vector<vi>& g, vi& btoa, vi& A, vi& B) {
	if (A[a] != L) return 0;
	A[a] = -1;
	for (int b : g[a]) if (B[b] == L + 1) {
		B[b] = 0;
		if (btoa[b] == -1 || dfs(btoa[b], L + 1, g, btoa, A, B))
			return btoa[b] = a, 1;
	}
	return 0;
}

int hopcroftKarp(vector<vi>& g, vi& btoa) {
	int res = 0;
	vi A(g.size()), B(btoa.size()), cur, next;
	for (;;) {
		fill(all(A), 0);
		fill(all(B), 0);
		/// Find the starting nodes for BFS (i.e. layer 0).
		cur.clear();
		for (int a : btoa) if(a != -1) A[a] = -1;
		rep(a,0,sz(g)) if(A[a] == 0) cur.push_back(a);
		/// Find all layers using bfs.
		for (int lay = 1;; lay++) {
			bool islast = 0;
			next.clear();
			for (int a : cur) for (int b : g[a]) {
				if (btoa[b] == -1) {
					B[b] = lay;
					islast = 1;
				}
				else if (btoa[b] != a && !B[b]) {
					B[b] = lay;
					next.push_back(btoa[b]);
				}
			}
			if (islast) break;
			if (next.empty()) return res;
			for (int a : next) A[a] = lay;
			cur.swap(next);
		}
		/// Use DFS to scan for augmenting paths.
		rep(a,0,sz(g))
			res += dfs(a, 0, g, btoa, A, B);
	}
}

vector<vector<int> > adj;

void sol() {
    cin >> n >> m;
    adj.clear();
    adj.resize(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> adj[i][j];
        }
    }
    
    auto check = [&](int h, bool ans) {
        vector<vector<int> > g(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (adj[i][j] >= h) g[i].push_back(j);
            }
        }

        vi btoa(m, -1); hopcroftKarp(g, btoa);
        int sum = 0;
        for (auto &x: btoa) {
            if (x != -1) sum++;
        }

        vector<int> c(n);
        if (ans) {
            for (int i = 0; i < m; i++) {
                if (btoa[i] != -1) c[btoa[i]] = i;
            }

            cout << h << '\n';
            for (int i = 0; i < n; i++) {
                cout << c[i] + 1 << " \n"[i+1==n];
            }
        }
        return sum >= n;
    };


    int hi = (int)1e9  +1, lo = 1;
    while (hi - lo > 1) {
        int mid = midpoint(lo, hi);
        if (check(mid, 0)) {
            lo = mid;
        } else {
            hi = mid;
        }
    }

    check(lo, 1);
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int testcase(1);
    while(testcase--) {
        sol();
        tt++;
    }
    return 0;
}
