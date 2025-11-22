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
    vector<array<int, 3>> adj(m);
    map<int, int> mp;
    for (int i = 0; i < m ;i++) {
        cin >> adj[i][0] >> adj[i][1] >> adj[i][2];
        mp[adj[i][1]]++;
    }

    int root = -1;
    for (int i = 1; i < n + 1; i++) {
        if (!mp[i]) {
            root = i;
            break;
        }
    }

    for (int i = 1; i < n + 1; i ++) {
        if (i != root ) cout << i << ' ' << root << '\n';
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

