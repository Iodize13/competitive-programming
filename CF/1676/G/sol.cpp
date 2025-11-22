#include<bits/stdc++.h>
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

int tt = 1;

int n, m;
string s;

void sol() {
    cin >> n;
    vector<int> par(n);
    vector<vector<int>> de(n);
    vector<vector<int>> adj(n);
    for (int i = 1; i < n ;i++) {
        cin >> par[i];
        par[i]--;
        adj[par[i]].push_back(i);
    }
    cin >> s;

    queue<pair<int, int>> qu;
    qu.push({0, 0});
    vector<bool> vis(n);
    while(!qu.empty()) {
        auto [cur, cd] = qu.front();
        de[cd].push_back(cur);
        qu.pop();
        vis[cur] = 1;
        for (auto &next: adj[cur]) {
            if (vis[next]) continue;
            qu.push(make_pair(next, cd + 1));
        }
    }

    int ans = 0;
    vector<pair<int, int>> ba(n);
    for (int i = n - 1; i >=0; i--) {
        for (int j = 0; j < sz(de[i]); j++) {
            int cur = de[i][j];
            ba[cur].first += s[cur] == 'W';
            ba[cur].second += s[cur] != 'W';
            for (auto &next: adj[cur]) {
                ba[cur].first += ba[next].first;
                ba[cur].second += ba[next].second;
            }
            if (ba[cur].first == ba[cur].second) ans++;
        }
    }
    
    cout << ans << '\n';
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

