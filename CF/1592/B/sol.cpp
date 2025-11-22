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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> b(all(a));

    if (is_sorted(all(a))) {
        cout << "YES\n";
        return;
    }

    sort(all(b));
    int mn = LLONG_MAX;
    for (int i = 0; i <n; i++) {
        if (a[i] != b[i]) mn = min(mn, max(abs((n - 1) - i), i));
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

