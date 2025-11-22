#include<bits/stdc++.h>
#define int long long int

using ll = long long;

using namespace std;

void runcase() {
    int a, b;
    cin >> a >> b;
    int ans = 0;
    for (int i = a; i <= b; i++) {
        if (i < 10) continue;
        int tmp = i;
        int tmp2 = i;
        int base = 1;
        int cnt = 0;
        while(tmp2) {
            tmp2 /= 10;
            base *= 10;
            cnt++;
        }
        base /= 10;
        for (int j = 0; j < cnt; j++) {
            int ld = tmp / base;
            // cerr << "ld: " << ld << '\n';
            // cerr << "base: " << base << '\n';
            // cerr << "tmp: " << tmp << '\n';
            tmp %= base;
            tmp *= 10;
            tmp += ld;
            if (tmp == i) break;
            if (tmp > i && tmp <= b && tmp >= a) {
                // cerr << i << ' '  << tmp << '\n';
                ++ans;
            }
        }
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--) {
        runcase();
    }
	return 0;
}
