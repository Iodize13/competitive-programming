#include<bits/stdc++.h>
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

int tt = 1;

int n, m, k;
string s;

void sol() {
    int y;
    cin >> n >> k >> y;
    vector<int> a(k);
    for (auto &x: a)
        cin>> x;

    sort(all(a), greater<int>());
    int ans = a[k - 2] - a[k - 1] == 2;
    // cerr << "ans: " << ans <<'\n';
    for (int i = k - 2 ; i >= 1; i--) {
        ans ++;
        ans += a[i - 1] - a[i] == 2;
        // cerr << "ans: " << ans <<'\n';
    }
    a[0] -= n;
    ans += a[k - 1] - a[0] == 2;

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

