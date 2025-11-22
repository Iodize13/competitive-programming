#include<bits/stdc++.h>

using namespace std;

using ll = long long;

void runcase() {
    cerr << "testcase: " << '\n';
    ll n, m, q, r, l, k;
    cin >> n >> l >> r >> k;
    int i = 0;
    //  you sure 63;
    for (i = 0; i <= 63; i++) {
        if ((1LL << i) > l) {
            break;
        }
    }
    if (n % 2 == 1) {
        cout << l << '\n';
        return ;
    }
    // you sure for n == 2?
    if (n == 2) {
        cout << -1 << '\n';
        return;
    }
    if (r < (1LL << i)) {
        cout << -1 << '\n';
        return;
    } else {
        if (n % 2 == 0) {
            if (k >= n - 1) {
            // if (k >= n - 2) {
                cerr << "k: " << k << '\n';
                cerr << "test\n";
                cout << (1LL << i) << '\n';
            } else {
                cout << l << '\n';
            }
        }
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
