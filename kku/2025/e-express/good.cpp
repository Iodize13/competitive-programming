#include<bits/stdc++.h>
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

int tt = 1;

int n, m, k;
string s;

void sol() {
    cin >> n >> m;
    vector<map<int, int> > adj(n);

    string ret = to_string(n) + "," + to_string(m) + ":";
    map<pair<int, int>, int> mp;
    for (int i = 0; i < m; i++) {
        int u, v, r;
        cin >> u >> v >> r;
        ret+=to_string(u) + "," + to_string(v) + "," + to_string(r) + ":";
        --u;
        --v;
        adj[u][v] = r;
        adj[v][u] = r;
        if (u > v) swap(u, v);
        mp[make_pair(u, v)] = i;
    }

    // if (tt == 42) {
    //     cout << ret << '\n';
    //     exit(0);
    // }

    auto djk = [&]() {
        set<pair<int, int> > st;
        vector<int> dis(n, (int)1e13);
        vector<int> road(n, -1);
        st.insert({0, 0});
        dis[0] = 0;

        while(!st.empty()) {
            auto [d, node] = *(st.begin());
            st.erase(*(st.begin()));

            for (auto &[next, weight]: adj[node]) {

                if (d + weight < dis[next]) {
                    if (dis[next] != (int)1e13) {
                        st.erase({dis[next], next});
                    }
                    dis[next] = d + weight;
                    road[next] = mp[make_pair(min(next, node), max(next, node))];

                    st.insert({dis[next], next});
                }
            }
        }

        return dis[n - 1];
    };

    int og = djk();
    cerr << "og: " << og << '\n';
    set<int> ans;
    for (int i = 0; i < n; i++) {
        int j = 0;
        for (auto &[key, val]: adj[i]) {
            // cerr << "val: " << val << '\n';
            val += 2;
            // cerr << "val: " << val << '\n';
            // cerr << "adj[key][i]: " << adj[key][i] << '\n';
            adj[key][i] += 2;
            // cerr << "adj[key][i]: " << adj[key][i] << '\n';
            int temp = djk();
            // cerr << "temp: " << temp << '\n';
            // cerr << "temp: " << temp << '\n';
            if (temp - og <= 1) ans.insert(mp[make_pair(min(i, key), max(i, key))]);
            val -= 2;
            adj[key][i] -= 2;
            j++;
        }
    }

    cout << sz(ans) << ' ';
    for (auto &x: ans) cout << x + 1 << ' ';
    cout << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int testcase(1);
    cin >> testcase;
    while(testcase--) {
        sol();
        tt++;
    }
    return 0;
}

