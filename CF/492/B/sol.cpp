#include<bits/stdc++.h>
#define int long long
#define ld long double
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

int tt = 1;

int n, m;
ld k;
string s;

void sol() {
    cin >> n >> k;
    ld ans = 0.L;
    vector<ld> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(all(a));

    ans = max(ans, a[0]); 
    ans = max(ans, k - a[n - 1]); 
    for (int i = 1; i < n; i++) {
        ans = max(ans, abs(a[i - 1] - a[i]) / 2.L);
    }

    cout << setprecision(12) << fixed << ans << '\n';
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

