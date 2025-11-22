#include<bits/stdc++.h>
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

int tt = 1;

int n, m, k;
string s;

vector<vector<int>> Y;
vector<vector<int>> X;
map<pair<int, int>, bool> vis;

void dfs(int r, int c) {
    if (vis[make_pair(c, r)] == 1) {
        return;
    }
    vis[make_pair(c, r)] = 1;
    // cerr << "dfs: " << r << ' ' << c << '\n';
    for (auto &next: Y[r]) {
        dfs(r, next);
    }
    for (auto &next: X[c]) {
        dfs(next, c);
    }
}

void sol() {
    cin >> n;
    int sx = 0;
    int sy = 0;
    X.assign(1001, vector<int>());
    Y.assign(1001, vector<int>());
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        int u, w;
        cin >> u >> w;
        v[i].first = u;
        v[i].second = w;
        if (i == 0) {
            sx = u;
            sy = w;
        }
        Y[w].push_back(u);
        X[u].push_back(w);
    }

    int ans = 0;
    for (auto &[F, S]: v) {
        if (vis[make_pair(F, S)] == 1) continue;
        // cerr << "S: " << S << ", F:" << F << '\n';
        dfs(S, F);
        ans++;
    }

    cout << ans  - 1 << '\n';
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

