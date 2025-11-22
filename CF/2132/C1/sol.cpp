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
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < (b); ++i)

using namespace std;
int n, m, k;

void sol() {
    cin >> n;
    int f = (int)pow(3LL, 18LL);
    int ans = 0LL;
    for (int i = 18; i >= 0; i--, f /= 3LL) {
        // cerr << "f: " << f << endl;
        ans += (n / f) * (f*3LL + (f/3LL)*i);
        if (f <= n) {
            n -= (n / f) * f;
        }
    }

    cout << ans << '\n';
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

