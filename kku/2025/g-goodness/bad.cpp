#include<bits/stdc++.h>
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

int tt = 1;

int n, m, k;
string s;

void sol() {
    cin >> n;
    vector<vector<int> > g(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        --x;
        g[x].push_back(i);
    }

    int ans = 0;
    vector<int> vis(n);
    set<int> a;
    vector<int> col(n);
    set<pair<int, int> > b;
    auto dfs = [&](int node, bool good) {

        stack<int> st;
        st.push(node);
        a.insert(node);
        col[node] = 2 - good;
        b.insert({node, col[node]});
        int cnt = good;
        while(!st.empty()) {
            auto cur = st.top();
            st.pop();
            if (vis[cur]) continue;
            vis[cur] = 1;
            for (auto &next: g[cur]) {
                if (vis[next]) {
                    if (col[next] == 1) {
                        if (col[cur] == 1) cnt--;
                        col[cur] = 2;
                        b.erase({cur, 1});
                        b.insert({cur, col[cur]});
                    }
                    continue;
                }
                col[next] = 3 - col[cur];
                if (col[next] == 1) {
                    cnt++;
                }
                st.push(next);
                a.insert(next);
                b.insert({next, col[next]});
            }
        }

        return cnt;
    };

    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        b.clear();
        int mx = dfs(i, true);
        for (auto &x: a) {
            vis[x] = 0;
        }

        auto good = b;
        b.clear();
        if (int temp2 = dfs(i, false); temp2 > mx) {
            mx = temp2;
        } else {
            for (auto &[F, S]: b) {
                col[F] = S;
            }
        }
        ans += mx;
        a.clear();
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

