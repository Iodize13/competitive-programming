#include<bits/stdc++.h>
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

int tt = 1;

int n, m, k;
string s;

void sol() {
    cin >> n >> k;
    vector<int> a(n);
    vector<int> pref(n + 1);
    pref[0] = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n ;i++) {
        pref[i] = pref[i - 1] + a[i - 1];
    }

    int ans = 0;
    int mn = LLONG_MAX;
    for (int i = k; i <= n; i++) {
        // cerr << "cerr: " << i << ' ' <<  pref[i] << ' ' << pref[i - k] << '\n';
        if (pref[i] - pref[i - k] < mn) {
            ans = i - k;
            mn = pref[i] - pref[i - k];
        }
    }

    // cerr << "mn: " << mn << '\n';
    cout << ans + 1 << '\n';
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

