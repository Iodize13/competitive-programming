#include<bits/stdc++.h>
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

int tt = 1;

int n, m, k;
string s;

void sol() {
    cin >> m >> n;
    vector<int> a(m);
    for (int i = 0; i < m; i++) 
         cin >> a[i];

    vector<int> b(n);
    for (int i = 0 ; i < n; i++) 
        cin >> b[i];

    int mx = -LLONG_MAX;
    for (int i = 0; i < m ;i++) {
        auto it = upper_bound(all(b), a[i]);
        if (it != b.end()) {
            int temp = abs(a[i] - *it);
            if (it != b.begin()) temp = min(temp, abs(a[i] - *prev(it)));
            mx = max(mx, temp);
        } else {
            mx = max(mx, abs(a[i] - *prev(it))); 
        }
    }

    cout << mx << '\n';
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

