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
    vector<int> a(n + 1);
    for (int i = 1; i <= n ;i++) {
        for (int j = i; j <= n; j+=i) {
            a[j] ^= 1;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans+= a[i];
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

