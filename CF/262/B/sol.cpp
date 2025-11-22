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
    vector<int> a; a.reserve(n);
    vector<int> b; b.reserve(n);
    for (int i = 0; i <n ; i++) {
        int x;
        cin >> x;
        if (x >= 0) a.push_back(x);
        else b.push_back(x);
    }

    sort(all(a));
    sort(all(b));
    for (int i = 0; i < sz(b) && k; i++, k--) {
        b[i] *= -1;
    }

    if (k % 2 == 1) {
        if (a.empty()) {
            b[sz(b) - 1] *= -1;
        } else if (b.empty()) {
            a[0] *= -1;
        } else {
            if (a[0] < b[sz(b) - 1]) {
                a[0] *= -1;
            } else {
                b[sz(b) - 1] *= -1;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < sz(a); i++) ans += a[i];

    for (int i = 0; i < sz(b); i++) ans += b[i];

    cout << ans << '\n';

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

