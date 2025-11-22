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
    vector<vector<int> > g(n, vector<int>(m));
    queue<pair<int, int>> st;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            g[(n - i)/2 ][(m - j) / 2] = n / 2 + m / 2;
            st.push({(n - i)/ 2, (m - j) / 2});
        }
    }

    auto valid = [&](int r, int c) {
        return r >= 0 && r < n && c >= 0 && c < m;
    };

    int dx4[4] = {-1, 0, 1, 0};
    int dy4[4] = {0, 1, 0, -1};
    while(!st.empty()) {
        auto [r, c] = st.front();
        st.pop();
        for (int i = 0; i < 4; i++) {
            int ni = r + dy4[i];
            int nj = c + dx4[i];
            if (valid(ni, nj) && !g[ni][nj]) {
                st.push({ni, nj});
                g[ni][nj] = g[r][c] + 1;
            }
        }
    };

    multiset<int> ans;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans.insert(g[i][j]);
        }
    }

    for (auto &x: ans) cout << x << ' ';
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

