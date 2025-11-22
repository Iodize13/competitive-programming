#include<bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()

using namespace std;

void sol() {
    int n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));
    for (int i  =0; i < n; i++) 
        for (int j = 0; j < n; j++) 
            cin >> grid[i][j];

    vector<vector<int>> ans(n);
    for (int i = 0; i < n; i++) {
        ans[i].push_back(i + 1);
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '1') ans[j].push_back(i + 1);
        }
    }

    for (auto X: ans) {
        cout << sz(X) << ' '; 
        for (auto Y: X) {
            cout << Y << ' ';
        }
        cout << '\n';
    }
}

int32_t main() {
    int tt;
    cin >> tt;
    while(tt--) sol();
}
