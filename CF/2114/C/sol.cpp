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
    for(auto &x: a)
        cin >> x;

    int ans = 1;
    int last = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] - last < 2) {
            continue;
        }
        last = a[i];
        ans++;
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

