#include<bits/stdc++.h>
#define int long long
#define sz(x) (int)(x).size()

using namespace std;

void sol() {
    int n;
    cin >> n;
    string x = to_string(n - (n / 2));
    string y = to_string(n / 2);
    int cnt = 0;
    for (int i = sz(x) - 1; i > 0 ;i--) {
        if (x[i] == '0') {
            cnt++;
        } else {
            break;
        }
    }
    cerr << x << '\n';
    cerr << cnt << '\n';
    bool ok = false;
    if (cnt && n % 2 != 0) {
        int sum = 0;
        for (int i = 0; i < cnt; i++) {
            sum += (4 + (ok)) * (int)pow(10, i);
            ok = !ok;
        }
        cout << n - (n / 2) + sum << ' ' << n / 2 - sum << '\n';
    } else {
        cout << n - (n / 2) << ' ' << n / 2 << '\n';
    }
}

int32_t main() {
    int tt;
    cin >> tt;
    while(tt--) sol();
}
