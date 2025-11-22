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
    int m = sz(to_string(n));
    vector<int> d;
    vector<int> b;
    for (int i = 1; i < (1LL << (m - 1)); i++) {
        int temp = i;
        int k = 0;
        while (temp > 0) {
            temp >>= 1;
            k++;
        }
        int cur = 0;
        for (int j = 0; j < k; j++) {
            cur += !!((1LL << j) & i) * (n % (int)pow(10LL, j + 1) / (int)pow(10LL, j)) * (int)pow(10LL, j);
        }

        // cerr << "cur: " << cur << '\n';
        // cerr << cur * (int)pow(10, m - k) << '\n';
        // sleep(1);
        if(cur + cur * (int)pow(10LL, m - k) == n) b.push_back(cur);
    }

    cout << sz(b) << '\n';
    if (!sz(b)) {
        return;
    }
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

