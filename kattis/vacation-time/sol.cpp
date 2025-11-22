#include<bits/stdc++.h>
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;
int n, m, k;

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt = 1, testcase(1);

    auto sol = [&]() {
        cin >> n >> m;
        vector<vector<pair<int, int>> > adj(n);
        vector<vector<pair<int, int> >> mp(n); 
        vector<vector<pair<int, int>> > bw(n);
        for (int i = 0; i < m; i++) {
            int u, v, r;
            string s;
            cin >> u >> v >> r >> s;
            adj[u].push_back({v,r});
            bw[v].push_back({u, r});
            if (s == "A380") {
                mp[u].push_back({v, r});
            }
        }
        
        set<pair<int, int> > st;
        st.insert({0, 0});
        vector<int> dist(n, (int)1e17);
        dist[0] = 0;
        while(!st.empty()) {
            auto [cost, node] = *st.begin();
            st.erase(st.begin());
            for (auto &[next, ncost]: adj[node]) {
                if (cost + ncost < dist[next]) {
                    dist[next] = cost + ncost;
                    st.insert({dist[next], next});
                }
            }
        }

        // for (auto &x: dist) cerr << x << ' ';
        // cerr << '\n';

        st.clear();
        st.insert({0, n-1});
        vector<int> dist2(n, (int)1e17);
        dist2[n - 1] = 0;
        while(!st.empty()) {
            auto [cost, node] = *st.begin();
            st.erase(st.begin());
            for (auto &[next, ncost]: bw[node]) {
                if (cost + ncost < dist2[next]) {
                    dist2[next] = cost + ncost;
                    st.insert({dist2[next], next});
                }
            }
        }
        // for (auto &x: dist2) cerr << x << ' ';
        // cerr << '\n';

        int ans = (int)1e17;
        for (int i = 0; i < n; i++) {
            if (!sz(mp[i])) continue;
            for (int j = 0; j < sz(mp[i]); j++) {
                // cerr << "yoo\n";
                // cerr << "i: " << i << '\n';
                // cerr << "mp[i][j].first: " << mp[i][j].first << '\n';
                ans = min(ans, dist[i] + mp[i][j].second + dist2[mp[i][j].first]);
            }
        }

        cout << (ans >= (int)1e17 ? -1 : ans) << '\n';
    };

    while(testcase--) {
        sol();
        tt++;
    }
    return 0;
}

