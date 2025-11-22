#include <cstdint>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <string>
#include <cstring>
#include <bitset>
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < (b); ++i)

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;

int n, m, k;

void sol() {
    cin >> n >> m;
    vi a(n), r(n);
    for (auto &x: a) {
        cin >> x;
    }

    for(auto &x: r) {
        cin >> x;
    }

    auto isqrt = [&](int x) {
        int aa = sqrt(x);
        while(aa * aa > x) aa--;
        while((aa+1) * (aa+1) <= x) aa++;
        return aa;
    };

    map<int, int> mp;
    rep(i,0,n) {
        rep(j,-r[i], r[i] + 1) {
            int d = r[i]*r[i]-j*j;
            int y = isqrt(d);
            mp[a[i] + j] = max(mp[a[i] + j], y);
        }
    }
    
    int ans = 0;
    for(auto &[x, f]: mp) ans += 2LL * f + 1LL;
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

