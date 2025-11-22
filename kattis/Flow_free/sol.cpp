#include <iostream>
#include <vector>
#include <map>
#include <cstdint>
#include <array>
#include <stack>
using namespace std;

#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)

const int mod = (int)1e9 + 7;

void sol();

int32_t main() {
    send help

    int testcase(1);

    while(testcase--) {
        sol();
    }
    return 0;
}

void sol() {
    vector<array<char, 4> > b(4);
    int hasy = false;
    rep(i,0,4) {
        rep(j,0,4) {
            cin >> b[i][j];
            if (b[i][j] == 'Y') hasy = true;
        }
    }

    stack<vector<array<char, 4> > > st;
    st.push(b);
    vector<char> cols = {'r', 'g', 'b'};
    if (hasy) cols.push_back('y');

    int dx4[4] = {-1, 0, 1, 0};
    int dy4[4] = {0, 1, 0, -1};
    vector<array<bool,4> > vis(4);

    auto valid = [](int r, int c) {
        return r >= 0 && r < 4 && c >=0 && c < 4;
    };

    bool found = false;
    int sum = 0;
    auto dfs = [&](auto &&self,int r, int c, char goal, vector<array<char, 4 > > &g, int cnt) {
        if (g[r][c] == goal && !cnt) {
            vis[r][c] = 1;
            found = true;
            sum += cnt;
            return; 
        }
        if (vis[r][c]) return;
        vis[r][c] = 1;

        rep(i,0,4) {
            int ny = r + dy4[i];
            int nx = c + dx4[i];
            if (valid(ny, nx) && !vis[ny][nx] && (g[ny][nx] == tolower(goal) || g[ny][nx] == goal)) self(self, ny, nx, goal, g, cnt - 1);
        }
        vis[r][c] = false;
    };

    while (!st.empty()) {
        auto cur = st.top();
        st.pop();
        bool ok = false;
        rep(i,0,4) {
            if (ok) break;
            rep(j,0,4) {
                if (cur[i][j] == 'W') {
                    for(auto &c: cols) {
                        cur[i][j] = c;
                        st.push(cur);
                    }
                    ok = true;
                    break;
                }
            }
        }
        if (!ok) {
            bool ans = true;
            sum = 0;
            vis.assign(4, array<bool, 4>());
            int cnt = 0;
            map<char, int> mp;
            rep(i,0,4) {
                rep(j,0,4) {
                    mp[(char)tolower(cur[i][j])]++;
                }
            }
            rep(i,0,4) {
                rep(j,0,4) {
                    if (!vis[i][j] && isupper(cur[i][j])) {
                        cnt++;
                        cur[i][j] = (char) tolower(cur[i][j]);
                        found = false;
                        dfs(dfs, i, j,(char) toupper(cur[i][j]), cur, mp[cur[i][j]] - 1);
                        ans &= found;
                    }
                }
            }

            if (ans) {
                cout << "solvable\n";
                return;
            }
        }
    }
        
    cout << "not solvable\n";
}
