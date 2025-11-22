#include<bits/stdc++.h>
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

int tt = 1;

int n, m, k;
string s;
vector<vector<int> > adj;

int mx = 1;
int nx = 0;

void sol() {
    mx = 0;
    nx = 0;
    cin >> n;
    adj.clear();
    adj.resize(n);
    string ret = to_string(n) + ",";
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        ret += to_string(u) + ":" + to_string(v) + ",";
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    stack<int> st;
    st.push(0);
    vector<int> vis(n, 0);
    vector<int> de(n, 0);
    while(!st.empty()) {
        auto cur = st.top();
        st.pop();
        if (vis[cur]) continue;
        vis[cur] = 1;
        for (auto &next: adj[cur]) {
            if (sz(adj[next]) == 1) {
                //cerr << "cur: " << cur << ", next: " << next << '\n';
                de[cur]++;
                if(de[cur] > mx) {
                    //cerr << "inside, cur: " << cur << ", next: " << next << '\n';
                    //cerr << "mx: " << mx << '\n';
                    mx = de[cur];
                    nx = cur;
                }
            }
            if (vis[next]) continue;
            st.push(next);
        }
    }

    // cerr << "nx: " << nx << '\n';
    // cerr << "mx: " << mx << '\n';
    vis.assign(n, 0);
    int ans = 0;
    vis[nx] = 1;
    for (auto &node: adj[nx]) {
        if (sz(adj[node]) == 1) continue;
        stack<int> sk;
        //cerr << "node: " << node << '\n';
        sk.push(node);
        while(!sk.empty()) {
            auto cur = sk.top();
            sk.pop();
            if (vis[cur]) continue;
            vis[cur] = 1;
            for (auto &next: adj[cur]) {
                if (vis[next]) continue;
                if (sz(adj[next]) == 1) {
                    //cerr << "cur: " << cur << ", next: " << next << '\n';
                    ans++;
                }
                sk.push(next);
            }
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

