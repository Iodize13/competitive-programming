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
#include <cmath>
#include <unistd.h>
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < (b); ++i)

using namespace std;
int n;

void sol() {
    cin >> n;
    vector<int> b;
    for (int i = 1; i <= 17; i++) {
        if (n % ((int)pow(10LL, i) + 1) == 0) {
            // cerr << "dbg: " << (int)(pow(10LL, i) + 1) << '\n';
            b.push_back(n / ((int)pow(10LL, i) + 1));
        }
    }

    cout << sz(b) << '\n';
    if (!sz(b)) {
        return;
    }

    sort(all(b));
    for (auto &x: b) cout << x << ' ';
    cout << '\n';
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

