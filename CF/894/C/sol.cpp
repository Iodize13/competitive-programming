#include<bits/stdc++.h>
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

int tt = 1;

int n, m;
string s;

void sol() {
    cin >> n;
    vector<int> a(n);
    vector<int> mp((int)1e6 + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]] = 1;
    }

    vector<int> ans;
    for (int i = 0; i < n; i++) {
        int cur = a[i];
        for (int j = i ; j < n; j++) {
            cur = gcd(cur, a[j]);
            if (!mp[cur]) {
                cout << -1 << '\n';
                return;
            }
        }
    }

    cout << n << '\n';
    for (int i = 0; i < n; i++) {
        cout << a[i] << " \n"[i == n - 1];
    }
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

