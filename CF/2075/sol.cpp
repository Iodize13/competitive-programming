#include<bits/stdc++.h>
#define int long long int

using ll = long long;

using namespace std;

void runcase() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    int mx = -INT_MAX;
    for (int i = 0; i < m; i++) 
        cin >> a[i];

    sort(a.begin(), a.end());
    int ans = 0;
    for (int i = (n + 1) / 2; i < n; i++) {
        int cm = m - (lower_bound(a.begin(), a.end(), i) - a.begin());
        int re = m - (lower_bound(a.begin(), a.end(), n - i) - a.begin());
        cerr << "upper_bound(a.begin(), a.end(), i): " << m - (upper_bound(a.begin(), a.end(), i) - a.begin() - 1) << '\n';
        cerr << "rm: " << re << ",cm : " << cm << '\n';
        ans += cm * (re - 1);
        if (!(n % 2 == 0 && i ==  n / 2)) ans += cm * (re - 1);
        // cerr << "i : " << i << ", pref[i]: " << pref[i] << '\n';
        // cerr << ", pref[n - i]: " << pref[n - i] << '\n';

    }

    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--) {
        runcase();
    }
	return 0;
}
