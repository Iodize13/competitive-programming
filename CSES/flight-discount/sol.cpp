#include<bits/stdc++.h>
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;
int n, m, k;

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int testcase(1);
    string s;

    auto sol = [&]() {
        cin >> n >> m;
        vector<vector<pair<int, int> > > adj(n);
        vector<vector<pair<int, int> > > bw(n);
        for (int i = 0; i < m; i++) {
            int u, v, c;
            cin >> u >> v >> c;
            --u;
            --v;
            adj[u].push_back({v, c});
            bw[v].push_back({u, c});
        }

        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
        vector<int> dist(n, (int)1e18);
        pq.push({0, 0});
        dist[0] = 0;
        while(!pq.empty()) {
            auto [cost, node] = pq.top();
            pq.pop();
            if (cost != dist[node]) continue;
            for (auto &[next, ncost]: adj[node]) {
                if (cost + ncost < dist[next]) {
                    dist[next] = cost + ncost;
                    pq.push({dist[next], next});
                }
            }
        }
        
        pq = priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > >();
        vector<int> dist2(n, (int)1e18);
        pq.push({0, n - 1});
        dist2[n - 1] = 0;
        while(!pq.empty()) {
            auto [cost, node] = pq.top();
            pq.pop();
            if (cost != dist2[node]) continue;
            for (auto &[next, ncost]: bw[node]) {
                if (cost + ncost < dist2[next]) {
                    dist2[next] = cost + ncost;
                    pq.push({dist2[next], next});
                }
            }
        }

        int ans = LLONG_MAX;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < sz(adj[i]); j++) {
                ans = min(ans, dist[i] + adj[i][j].second / 2 + dist2[adj[i][j].first]);
            }
        }

        cout << ans << '\n';
    };

    while(testcase--) {
        sol();
    }
    return 0;
}

