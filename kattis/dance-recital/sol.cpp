#include<bits/stdc++.h>
#define ll long long
#define int long long

using namespace std;

int n;

bool vis[12];
vector<string> per;

int ans = LLONG_MAX;
map<pair<int, int>, int> v2;

void perm(int i, int prev, int cnt) {
    if (i == 0) {
        ans = min(ans, cnt);
        return;
    }   
    for (int j = 0; j < n; j++) {
        if (vis[j]) continue;
        vis[j] = 1;
        if (prev != -1) perm(i - 1, j, cnt + v2[make_pair(prev, j)]);
        else perm(i - 1, j, cnt);
        vis[j] = 0;
    }
}

void solve() {
    cin >> n;
    memset(vis, 0, sizeof vis);
    vector<string> v(n);
    for (int i = 0 ; i < n; i++) {
        cin >> v[i];
    }

    cerr << "tset\n";
    for (int i = 0; i < n; i++) {
        map<char, int> ma;
        for (int k = 0; k < v[i].size(); k++) {
            ma[v[i][k]]++;
        }
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            int cnt2 = 0LL;
            for (int k = 0; k < v[j].size(); k++) {
                if (ma[v[j][k]]) cnt2++;
            }
            v2[make_pair(i, j)] = cnt2;
        }
    }
    perm(n, -1, 0);
    // for (int i = 0; i < per.size(); i++) {
    //     map<char, int> mp;
    //     map<char, int> mc;
    //     int cnt = 0;
    //     // for (int k = 0; k < v[per[i][0] - '0'].size(); k++) {
    //     //     mp[v[per[i][0] - '0'][k]]++;
    //     // }
    //     for (int j = 1; j < per[i].size(); j++) {
    //         // for (int k = 0; k < v[per[i][j] - '0'].size(); k++) {
    //         //     if (mp[v[per[i][j] - '0'][k]]) cnt++;
    //         //     mc[v[per[i][j] - '0'][k]]++;
    //         // }
    //         // mp = mc;
    //         // mc.clear();
    //         cnt += v2[make_pair(per[i][j - 1] - '0', per[i][j] - '0')];
    //     }
    // }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    clock_t z = clock();
    solve();
    cerr << fixed << (double)(clock() - z) / CLOCKS_PER_SEC << setprecision(9) << '\n';
    return 0;
}
