#include<bits/stdc++.h>
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;
int n, m;

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    auto sol = [&]() {
        unordered_set<string> us;
        string board;
        for (int i = 0; i < 4; i++) {
            string x;
            cin >> x;
            board +=x;
        }
        // cerr << board << endl;

        // string init ="................";
        queue<string> q;
        q.push(board);

        auto valid = [](int r, int c) {
            return r >= 0 && r < 4 && c >=0 && c < 4;
        };

        auto dfs = [&](vector<vector<char> > &g, char cur, int ry, int cx) {
            int dx4[4] = {-1, 0, 1, 0};
            int dy4[4] = {0, 1, 0, -1};
            stack<pair<int, int> > st;
            st.push({ry, cx});
            bool ok = true;
            while(!st.empty()) {
                auto [r, c] = st.top();
                st.pop();
                g[r][c] = '.';
                bool f = 0;
                for (int i = 0; i < 4; i++) {
                    int nx = c + dx4[i];
                    int ny = r + dy4[i];
                    if (valid(ny, nx)) {
                        if(g[ny][nx] == cur) {
                            f = 1;
                            st.push({ny, nx});
                        }
                    } 
                }
                if(!f) {
                    ok = 0;
                    break;
                }
                if (!ok) break;
            }
        };

        auto cal = [&](string s) {
            vector<vector<char>> g(4, vector<char>(4));
            cerr << s << '\n';

            int k = 0;
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++, k++) {
                    g[i][j] = s[k];
                }
            }

            set<char> seen;
            k = 0;
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++, k++) {
                    if (seen.find(s[k]) == seen.end()) dfs(g, s[k], i, j);
                    seen.insert(s[k]);
                }
            }

            int cnt = 0;
            k = 0;
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++, k++) {
                    cnt += (s[k] == '.');
                }
            }

            return (cnt == 16);
        };

        while(!q.empty()) {
            // cerr << "test\n";
            string cur = q.front();
            q.pop();
            //if(us.find(cur) != us.end()) continue;
            us.insert(cur);
            if (cal(cur)) {
                cout << "solvable\n";
                return;
            }
            vector<char> col = {'R', 'G', 'B', 'Y'};
            for (auto &x: cur) {
                if (x == 'W') {
                    for (auto &y: col) {
                        x = y;
                        if(us.find(cur) == us.end()) {
                            us.insert(cur);
                            q.push(cur);
                        }
                        x = 'W';
                    }
                }
            }
        }
        cout << "not solvable\n";
    };

    sol();
    return 0;
}

