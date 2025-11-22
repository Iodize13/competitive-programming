#include<bits/stdc++.h>

using namespace std;

using ll = long long;

void runcase() {
    ll a, b, x, y;
    cin >> a >> b >> x >> y;
    if (a % 2 == 1 && a - b == 1) {
        cout << y << '\n';
        return;
    }
    if (b < a) {
        cout << -1 << '\n';
        return;
    }
    if (b == a) {
        cout << 0 << '\n';
        return;
    }
    if (a % 2LL == 1LL) {
        ll fc = ((b - a + 1LL) / 2LL);
        ll ans = ((b - a) -fc) * min(x, y) + fc*x;
        cerr << "case 1: \n";
        cout << ans << '\n';
    } else {
        ll fc = (b - a) / 2LL;
        cerr << "fc: " << fc << '\n';
        ll ans = ((b - a) - fc) * min(x , y) + fc* x;
        cerr << "case 2: \n";
        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int testcase(1); cin >> testcase;
    while(testcase--) {
        runcase();
    }
    return 0;
}
