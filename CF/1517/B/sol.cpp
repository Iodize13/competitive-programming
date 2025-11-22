#include<bits/stdc++.h>
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

int tt = 1;

int n, m;
string s;

void sol() {
    cin >> n >> m;
    vector<pair<int, int>> v(n * m);
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];        
            v[i * m + j].first = a[i][j];
            v[i * m + j].second = i;
        }
    }

    sort(all(v));
    // for (int i = 0; i < n * m; i++) cerr << v[i].first << ' '<< v[i].second << '\n';
    vector<vector<int>> ans(n, vector<int>(m));
    for (int i = 0; i < m; i++) {
        // cerr << v[i].second << '\n';
        ans[v[i].second][i] = v[i].first;
        a[v[i].second].erase(find(all(a[v[i].second]), v[i].first));
    }

//     for (int i = 0; i  < n; i++) {
//         for (int j = 0; j < m; j++) {
//             cout << ans[i][j] << " \n"[j == m - 1];
//         }
//     }
    // cerr << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0, k = 0; j < m; j++) {
            if (ans[i][j] != 0) continue;
            ans[i][j] = a[i][k];
            k++;
        }
    }
    // cerr << "test" << endl;

    for (int i = 0; i  < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ans[i][j] << " \n"[j == m - 1];
        }
    }
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

