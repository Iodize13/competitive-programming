#include<bits/stdc++.h>
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

int tt = 1;

int n, m, k;
string s;

void sol() {
    int l, r;
    cin >> l >> r;

    int temp = l;
    int bit = 0;
    while(temp) {
        temp >>= 1;
        bit++;
    }

    --bit;
    int ans = r - l + 1;
    for (int i = l; i <= r; i++) {
        ans -= ((i >> bit) & 1);
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

