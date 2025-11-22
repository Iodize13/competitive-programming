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
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

int tt = 1;

const int mod = 32768;

int n, m, k;
string s;

void sol() {
    cin >> n;
    vector<int> a(n);
    for (auto &x: a)
        cin >> x;

    // //cerr << 0b111111111111010 << '\n';
    // cerr << bitset<15>(4124) << '\n';
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        int mx = 0;
        int add = 0;
        if (!a[i]) continue;
        for (int j = 0; j < 16;j++) {
            // if (!((1LL<< j) & a[i])) continue;
            int y = (1LL << j) - a[i] % (1LL << j);
            int temp = a[i];
            int cnt = 0;
            while (!(temp & 1)) { 
                temp >>= 1;
                cnt++;
            } 
            if (mx <= j - cnt - y) {
                // cerr << "a[i]:" << a[i] << ' ' << "test\n";
                // cerr << j << '\n';
                // cerr << cnt << '\n';
                // cerr << y << '\n';
                mx = j - cnt - y;
                add = y; 
            }
        }
        a[i] += add;
        ans[i] += add;
        while (a[i] % mod) {
            a[i] *= 2;
            ans[i]++;
        }
    }

    for (auto &x: ans) cout << x << ' ';
    cout << '\n';
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

