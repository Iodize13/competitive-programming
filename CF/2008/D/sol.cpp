#include <bits/stdc++.h>
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < (b); ++i)

using namespace std;
int n, m, k;

void sol() {
    cin >> n;
    vector<int> par(n);
    for (auto &x: par)
        cin >> x;

    for (auto &x: par) x--;

    string s;
    cin >> s;

    vector<bool> vis(n);
    vector<int> depth(n);
    for (int i = 0; i < n ; i++) {
        if (vis[i]) continue;
        int cur = i;
        vector<int> x;
        vis[cur] = 1;
        x.push_back(i);
        cur = par[cur];
        bool ok = false;
        while(1) {
            if (vis[cur]) break;
            vis[cur] = 1;
            x.push_back(cur);
            cur = par[cur];
            if (cur == i) {
                ok = true;
                break;
            }
        }

        // for (auto &y: x) cerr << y << ' ';
        // cerr << '\n';
        if (sz(x)) {
            // cerr << "test" << endl;
            int cnt = 0;
            for (int j = sz(x) - 1; j >= 0; j--) {
                cnt += s[x[j]] == '0';
                depth[x[j]] = cnt;
            }

            if (ok) {
                for (int j = 0; j < sz(x); j++) {
                    depth[x[j]] = depth[x[0]];
                }
            }
        } else {
            depth[i] = s[i] == '0';
        }
    }
    for (auto &x: depth) cout << x << ' ';
    cout << '\n';
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

