#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <deque>
#include <stack>
#include <cstdint>
#include <bitset>
#include <cstring>
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < (b); ++i)

using namespace std;
int n, m, k;

void sol() {
    cin >> n >> m;
    vector<vector<int> > g(m, vector<int>(n));
    rep(i,0,n) {
        rep(j,0,m) {
            cin >> g[j][i];
        }
    }
    
    // rep(i,0,m) {
    //     rep(j,0,n) {
    //         cout << g[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    vector<vector<int> > a = g;
    sort(all(a));
    int ind0 = 0, ind1 = 0;
    int cnt = 0;
    rep(i,0,m) {
        rep(j,0,n) {
            if (a[i][j] != g[i][j]) {
                // cerr << "i: " << i << '\n';
                if (!cnt) ind0 = i;
                cnt++;
                ind1 = i;
                break;
            }
        }
    }

    if (cnt > 2) {
        cout << -1 << '\n';
        return;
    }

    rep(j,0,n) {
        swap(g[ind0][j], g[ind1][j]);
    }

    rep(i,1,m) {
        rep(j,0,n) {
            if (g[i - 1][j] > g[i][j]) {
                cout << -1 << '\n';
                return;
            }
        }
    }

    cout << ind0 + 1 << ' ' << ind1 + 1 << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt = 1, testcase(1);
    string s;
    cin >> testcase;

    while(testcase--) {
        sol();
        tt++;
    }
    return 0;
}

