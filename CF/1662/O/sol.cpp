#include<bits/stdc++.h>
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

int tt = 1;

int n, m, k;
string s;

vector<vector<bool> > vis;
vector<vector<bool> >  grid;
bool ans = false;
void dfs(int r, int c) {
    if (c == 720 && r == 21) {
        ans = true;
        return;
    }
    if (vis[r][c]) return;
    // cerr << "r: " << r << ", c: " << c << '\n';
    vis[r][c] = 1;
    if (r + 1 < 22) {
        if (grid[r + 1][(c + 1) % 721] == 0 && !vis[r + 1][(c + 1) % 721]) dfs(r + 1, (c + 1) % 721);
        if (grid[r + 1][((c - 1) + 721) % 721] == 0 && !vis[r + 1][((c - 1) + 721) % 721]) dfs(r + 1, ((c - 1) + 721) % 721);
    }
    if (r - 1 >= 0) {
        if (grid[r - 1][(c + 1) % 721] == 0 && !vis[r - 1][(c + 1) % 721]) dfs(r - 1 , (c + 1) % 721);
        if (grid[r - 1][((c - 1) + 721) % 721] == 0 && !vis[r - 1][((c - 1) + 721) % 721]) dfs(r - 1, ((c - 1) + 721) % 721);
    }
}

void sol() {
    cin >> n;
    vector<array<int, 3> > sg;
    vector<array<int, 3> > cr;
    for (int i = 0; i < n; i++) {
        char ty;
        cin >> ty;
        if (ty == 'C') {
            array<int, 3> temp;
            cin >> temp[0] >> temp[1] >> temp[2];
            cr.push_back(temp);
        } else {
            array<int, 3> temp;
            cin >> temp[0] >> temp[1] >> temp[2];
            sg.push_back(temp);
        }
    }
    vis.assign(22, vector<bool>(720 + 1, 0));
    grid.assign(22, vector<bool>(721, 0));
    for (int i = 0; i < sz(cr); i++) {
        if (cr[i][1] > cr[i][2]) {
            for (int j = cr[i][1] * 2; j >= 0; j--) {
                grid[cr[i][0]][j] = 1;
            }
            for (int j = 0; j <= cr[i][2] * 2; j++) {
                grid[cr[i][0]][j] = 1;
            }
        } else {
            for (int j = cr[i][1] * 2; j <= cr[i][2] * 2; j++) {
                grid[cr[i][0]][j] = 1;
            }
        }
    }

    for (int i = 0; i < sz(sg); i++) {
        for (int j = sg[i][0]; j <= sg[i][1]; j++) {
            grid[j][sg[i][2] * 2] = 1;
        }
    }

    for (int i = 0; i <= 20; i++) {
        for (int j = 0; j <= 720; j++) {
            cout << grid[i][j];
        }
        cout << '\n';
    }

    dfs(0,0);
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

