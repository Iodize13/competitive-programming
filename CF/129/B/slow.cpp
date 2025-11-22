#include<bits/stdc++.h>
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

int tt = 1;

int n, m, k;
string s;
vector<vector<int> > adj;
vector<int> vis;
vector<int> cycle;
stack<int> sk;
vector<int> en;
bool found = false;

void cyc(int node) {
    vector<int> from(n, -1);
    queue<pair<int, int> > sc;
    sc.push({node, -1});
    while (!sc.empty()) {
        auto [cur, par] = sc.front();
        sc.pop();
        vis[cur] = 1;
        for (auto &next: adj[cur]) {
            if (next == par) continue;
            if (vis[next]) {
                int temp = cur;
                while (temp != next) {
                    cycle.push_back(temp);
                    temp = from[temp];
                }
                cycle.push_back(next);
                return;
            }
            from[next] = cur;
            sc.push({next, cur});
        }
    }
}

void del(int node) {
    adj[node].clear();
    for (int j = 0; j < n; j++) {
        if (adj[j].empty()) continue;
        auto it = find(all(adj[j]), node);
        if (it != adj[j].end()) adj[j].erase(it);
    }
}

void sol() {
    cin >> n >> m;
    adj.assign(n, vector<int>());
    vis.assign(n, 0);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // cerr << "dbg: \n";
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < sz(adj[i]); j++) cerr << adj[i][j] << " \n"[j + 1 == sz(adj[i])];
    // }
    
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            found = false;
            cyc(i);
            for (auto &X: cycle) {
                del(X);
            }
            cerr << '\n';
            cycle.clear();
            sk = stack<int>();
        }
    }

    // cerr << "dbg: ";
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < sz(adj[i]); j++) cerr << adj[i][j] << " \n"[j + 1 == sz(adj[i])];
    // }

    int ans = 0;
    do {
        vis.assign(n, 0);
        en.clear();
        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;
            // cerr << "dbg:\n";
            sk.push(i);
            while(!sk.empty()) {
                auto cur = sk.top();
                sk.pop();
                if (vis[cur]) continue;
                vis[cur] = 1;
                if (sz(adj[cur]) == 1) en.push_back(cur);
                for (auto &next: adj[cur]) {
                    if (vis[next]) continue;
                    sk.push(next);
                }
            }
        }
        cerr << "dbg: \n";
        for (auto &X: en) {
            cerr << X  << ' ';
            del(X);
        }
        cerr << '\n';
        if (!en.empty()) ans++;
    } while(!en.empty());

    cout << ans << '\n';
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

