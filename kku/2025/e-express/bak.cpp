#include<bits/stdc++.h>
#define int long long
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

using namespace std;


int n, m;
vector<vector<pair<int, int>>> adj;

int f() {
    set<pair<int, int>> st;
    st.insert({0, 0});
    vector<int> dist(n, (int)1e13);
    dist[0] = 0;
    while(!st.empty()) {
        auto [dis, node] = *st.begin();
        st.erase(st.begin());
        for(int next = 0; next < n; next++) {
            if (adj[node][next].first == -1) continue;
            auto [F, S] = adj[node][next];
            if (dis + F < dist[next]) {
                if (dist[next] != (int)1e13) {
                    st.erase({dist[next], next});
                }
                dist[next] = dis + F;
                st.insert({dist[next], next});
            }
        }
    }
    return dist[n - 1];
}

void sol() {
    cin >> n >> m;
    adj.clear();
    adj.resize(n, vector<pair<int, int>>(n, make_pair(-1, -1)));
    // adj.assign(n, vector<pair<int,int>>(n, make_pair(-1, -1)));
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        adj[u][v] = {w, i + 1};
        adj[v][u] = {w, i + 1};
    }

    set<pair<int, int>> st;
    st.insert({0, 0});
    vector<int> dist(n, (int)1e13);
    dist[0] = 0;
    vector<int> path(n, -1);
    while(!st.empty()) {
        auto [dis, node] = *st.begin();
        st.erase(st.begin());
        for (int next = 0; next < n; next++) {
            if (adj[node][next].first == -1) continue;
            auto [F, S] = adj[node][next];
            if (dis + F < dist[next]) {
                if (dist[next] != (int)1e13) {
                    st.erase({dist[next], next});
                }
                dist[next] = dis + F;
                st.insert({dist[next], next});
                path[next] = node;
            }
        }
    }
    // for (auto X: dist) cerr << X << ' ';
    // cerr << '\n';
    int par = n - 1;
    
    vector<bool> vis(m + 1, 0);
    // cerr << "first" << endl;
    while(par != -1) {
        // cerr << par << ' ';
        int tmp = par;
        par = path[par];
        if (par == -1) break;
        // cerr << "in vec: " << adj[tmp][par].second << endl;
        vis[adj[tmp][par].second] = true;
    }
    // cerr << "sec" << endl;

    set<int> ans;
    for (int i = 0; i < n; i++) {
        for (int next = 0; next < n; next++) {
            if (adj[i][next].second != -1 && !vis[adj[i][next].second]) ans.insert(adj[i][next].second);
        }
    }

    // // for (auto X: ans) cerr << X << ' ';
    // cerr << '\n';

    for (int i = 0; i < n; i++) {
        for (int next = 0; next < n; next++) {
            if (adj[i][next].second != -1 && vis[adj[i][next].second]) {
                adj[i][next].first += 2;
                adj[next][i].first += 2;
                if (f() <= dist[n - 1] + 1) ans.insert(adj[i][next].second);
                adj[i][next].first -= 2;
                adj[next][i].first -= 2;
            }
        }
    }

    // cerr << '\n';
    // for (auto X: path) cerr << X << ' ';
    // cerr << '\n';
    
    // cerr << "ans: ";
    cout << sz(ans) << ' ';
    for (auto X: ans) cout << X << ' ';
    cout << '\n';
}

int32_t main() {
    int tt;
    cin >> tt;
    while(tt--) sol();
}
