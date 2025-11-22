#include<bits/stdc++.h>
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < (b); ++i)

using namespace std;
int n, m, k;

void sol() {
    cin >> n >> m;
    map<pair<int, int>, pair<int, int> > mp;
    vector<vector<pair<int, int> > > adj(n);
    for (int i = 0; i < m; i++) {
        // cerr << "test\n";
        int u, v, c;
        cin >> u >> v >> c;
        --u;
        --v;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
        if (u > v) swap(u, v);
        mp[make_pair(u, v)] = {c, i};
    }

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    vector<int> dist(n, (int)1e18);
    vector<int> end_dist(n, (int)1e18);
    vector<int> par(n);
    vector<int> path(m);
    dist[0] = end_dist[n - 1] = 0;
    pq.push({0, 0});
    while(!pq.empty()) {
        auto [cost, node] = pq.top();
        pq.pop();

        if (cost != dist[node]) continue;
        for (auto &[next, nc]: adj[node]) {
            if (nc + cost < dist[next]) {
                dist[next] = nc + cost;
                pq.push({dist[next], next});
                par[next] = node;
            }
        }
    }

    int cur = n - 1;
    while(cur != 0) {
        int u = cur, v = par[cur];
        if (u > v) swap(u, v);
        path[mp[make_pair(u, v)].second] = 1;
        cerr << "mp: " << mp[make_pair(u, v)].second << '\n';
        cur = par[cur];
    }

    set<int> st;
    for (int i = 0;i < m; i++) if (!path[i]) st.insert(i);

    pq.push({0, n - 1});
    while(!pq.empty()) {
        auto [cost, node] = pq.top();
        pq.pop();

        if (cost != end_dist[node]) continue;
        for (auto &[next, nc]: adj[node]) {
            if (nc + cost < end_dist[next]) {
                end_dist[next] = nc + cost;
                pq.push({end_dist[next], next});
            }
        }
        // for (auto &x: end_dist) cerr << x << ' ';
        // cerr << '\n';
    }

    int og = dist[n - 1];
    cerr << "og: " << og << '\n';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < sz(adj[i]); j++) {
            int u = i, v = adj[i][j].first;
            if (u > v) swap(u, v);
            int x = dist[i] + end_dist[adj[i][j].first] + mp[make_pair(u, v)].first + 2;
            cerr << "x: " << x << '\n';
            if (x - og <= 1) st.insert(mp[make_pair(u, v)].second);
        }
    }

    cout << sz(st) << ' ';
    for (auto &x: st) cout << x + 1 << ' ';
    cout << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt = 1, testcase(1);
    string s;
    cin >> testcase;

    while(testcase--) {
        sol();
        tt++;
    }
    return 0;
}

