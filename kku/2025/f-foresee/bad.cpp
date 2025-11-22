#include<bits/stdc++.h>
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

int tt = 1;

int n, m, k;
string s;

void sol() {
    cin >> n;
    vector<int> a(n);
    vector<bool> mp(2 * n + 1);
    for (auto &x: a) {
        cin >> x;
        mp[x] = true;
    }

    multiset<int> me;
    for (int i = 1; i <= 2* n; i++) {
        if (!mp[i]) me.insert(i);
    }   

    int ans = 0;
    int list[] = {0, n - 1};
    for (auto i: list) {
        if (*me.begin() < a[i]) {
            me.extract(me.begin());
            ans++;
        }
    }
    cerr << "TEST" << endl;
    for (int i = 1; i < n - 1; i++) {
        if (auto it = me.lower_bound(a[i]); it != me.end()) {
            me.extract(it);
            // for (auto &x: me) cout << x << ' ';
            // cout << '\n';
            ans++;
        }
    }

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
