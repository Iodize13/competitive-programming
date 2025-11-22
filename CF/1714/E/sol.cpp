#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <deque>
#include <stack>
#include <cstdint>
#include <bitset>
#include <cstring>
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < (b); ++i)

using namespace std;
int n, m, k;

void sol() {
    cin >> n;
    vector<int> a(n);
    for (auto &x: a)
        cin >> x;

    vector<int> t(20);
    for (int i = 1; i < 20;) {
        t[i] = 1;
        i += i % 10;
    }

    for (int i = 3; i < 20;) {
        t[i] = 3;
        i += i % 10;
    }

    int mn = INT64_MAX;
    int mx = -INT64_MAX;
    for (auto &x: a) {
        mn = min(mn, x);
        mx = max(mx, x);
        if (x % 10 == 1) {
            x = (x / 10) % 2 == 0 ? 1: 3;
        }
        if (x % 10 == 3 || x % 10 == 7 || x % 10 == 9) {
            x = (x / 10) % 2 == 1 ? 1: 3;
        }
        if (x % 5 == 0) x = 0;
        x %= 20;
        x = t[x];
    }

    bool ok = true;
    for (int i = 1; i < n; i++) {
        if (a[i] != a[i - 1]) ok = false;
    }

    if (ok) {
        if (!a[0]) {
            if (mn == mx) {
                cout << "YES\n";
                return;
            } else {
                cout << (mx - mn == 5 && mx % 10 == 0 ? "YES" : "NO") << '\n';
                return;
            }
        } else {
            cout << "YES\n";
            return;
        }
    } else {
            cout << "NO\n";
            return;
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt = 1, testcase(1);
    string s;
    cin >> testcase;

    while(testcase--) {
        sol();
        tt++;
    }
    return 0;
}

