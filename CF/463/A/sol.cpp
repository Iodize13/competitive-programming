#include<bits/stdc++.h>
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

int tt = 1;

int n, m, k;
string s;

void sol() {
    cin >> n >> m;
    int ans = -1;
    vector<pair<int, int> > a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    for (int i = 0; i < n; i++) {
        if (m == a[i].first && a[i].second == 0) ans = max(ans, 0LL);
        if (m > a[i].first) {
            // cerr << "i: " << i << '\n';
            if (a[i].second == 0) ans = max(ans, 0LL);
            else ans = max(ans, 100 - a[i].second);
        }
    }

    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int testcase(1);
    while(testcase--) {
        sol();
        tt++;
    }
    return 0;
}

