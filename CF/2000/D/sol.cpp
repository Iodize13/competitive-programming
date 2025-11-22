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
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    cin >> s;
    int l = 0;
    int r = n - 1;
    vector<int> pref(n + 1);
    pref[0] = 0;
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + a[i - 1];
    }

    int ans = 0;
    for (; l < r; l++) {
        if (s[l] == 'R') continue;
        while (r > l && s[r] != 'R') {
            r--;
        }
        if (r <= l) break;
        // cerr << "r: " << r << ", l: " << l << '\n';
        ans += pref[r + 1] - pref[l];
        r--;
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

