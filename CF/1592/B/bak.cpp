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
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    vector<pair<int, int>> b(all(a));

    if (is_sorted(all(a))) {
        cout << "YES\n";
        return;
    }

    sort(all(a));
    int mn = LLONG_MAX;
    for (int i = 0; i <n; i++) {
        // cerr << "abs(a[i].second - i): " << abs(a[i].second - i) << '\n';
        // cerr << "abs((n - 1) - a[i].second): " << abs((n - 1) - a[i].second) << '\n';
        // cerr << "a[i].second - 1: " << a[i].second << '\n';
        if (a[i].first != b[i].first) mn = min(mn, max({abs((n - 1) - a[i].second), a[i].second}));
    }

    if (mn >= m) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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

