#include<bits/stdc++.h>
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")

using namespace std;

int tt = 1;

int n, m, k;
string s;

vector<bool> vis;
vector<vector<int> > adj;
vector<int> left_pair;
vector<int> right_pair;

bool dfs(int u) {
  vis[u] = true;
  for (auto &v : adj[u]) {
    if (left_pair[v] == -1 ||
        (!vis[left_pair[v]] && dfs(left_pair[v]))) {
      left_pair[v] = u;
      right_pair[u] = v;
      return true;
    }
  }
  return false;
}

void sol() {
    cin >> n >> m;
    vector<vector<int> > a(n, vector<int>(m));
    vector<int> b;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            b.push_back(a[i][j]);
        }
    }
    auto last = unique(all(b));
    b.erase(last, b.end());
    
    auto check = [&](int h, bool ans) {
        adj.clear();
        adj.resize(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] >= h) {
                    adj[i].push_back(j);
                }
            }
        }


        right_pair.clear();
        right_pair.resize(n, -1);
        left_pair.clear();
        left_pair.resize(m, -1);

        vector<bool> used1(n, false);
        for (int v = 0; v < n; ++v) {
            for (int to : adj[v]) {
                if (left_pair[to] == -1) {
                    left_pair[to] = v;
                    right_pair[v] = to;
                    used1[v] = true;
                    break;
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            if (used1[i]) continue;  // Already paired.
            vis.clear();
            vis.resize(m, 0);
            dfs(i);
        }

        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (right_pair[i] != -1) cnt++;
        }

        if (ans) {
            for (int i = 0; i < n; i++) {
                cout << right_pair[i] + 1 << ' ';
            }   
        }
        return (cnt == n);
    };


    sort(all(b));
    int hi = sz(b), lo = 0;
    while (hi - lo > 1) {
        int mid = midpoint(lo, hi);
        if (check(b[mid], 0)) {
            lo = mid;
        } else {
            hi = mid;
        }
    }

    cout << b[lo] << '\n';
    check(b[lo], 1);
    cout << '\n';
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

