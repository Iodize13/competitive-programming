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
    vector<int> b(32);
    vector<int> a(n);
    for (int i = 0; i < n ;i++ ) {
        cin >> a[i];
    }

    int ans = a[0];
    for (int i = 1; i < n; i++) {
        ans &= a[i];
    }

    for (int i = 0; i < n; i++) {
        int j = 0;
        while(a[i]) {
            b[j] += (a[i] & 1);
            a[i] >>= 1;
            j++;
        }
    }

    vector<int> c;
    for (int i = 30; i >= 0; i--) {
        if (b[i] == n) continue;
        if (k >= n - b[i]) {
            c.push_back(i);
            k -= max(n - b[i], 0LL);
        }
    }

    for (auto &X: c) ans |= (1LL<<X);

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

