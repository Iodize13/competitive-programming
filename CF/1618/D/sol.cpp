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
    for (auto &x: a)
        cin >> x;

    sort(all(a));

    vector<int> b(a.end() - 2 * k, a.end());

    int ans = accumulate(a.begin(), a.end() - 2 *k, 0LL);
    // cerr << ans << '\n';

    for (int i = 0; i < sz(b) / 2; i++) {
        ans += b[i] / b[i + k];
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

