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
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <array>
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < (b); ++i)

using namespace std;
typedef vector<int> vi;
int n, m, k;
int tt = 1, testcase(1);

void sol() {
    cin >> n;
    vi d(n);
    for(auto &x: d) {
        cin >> x;
    }

    vi hi(n + 1), lo(n + 1);
    vi l(n), r(n);
    rep(i,0,n) {
        cin >> l[i] >> r[i];
    }
    // if (tt == 3441) {
    //     string ret = to_string(n) + ":";
    //     for (auto &x: d) ret += to_string(x) + ",";
    //     ret += ":";
    //     rep(i,0,n) {
    //         ret += to_string(l[i]) + ":" + to_string(r[i])+ ",";
    //     }
    //     cout << ret << '\n';
    // }


    int lo0 = 0, hi0 = 0;
    rep(i,0,n) {
        if (d[i] == 1) {
            lo0++;
            hi0++;
        }
        lo0 = max(l[i], lo0);
        hi0 = min(r[i], hi0);
        if (d[i] == -1) hi0 = min(r[i], hi0 + 1);
        if (lo0 > hi0) {
            cout << -1 << '\n';
            return;
        }
        lo[i + 1] = lo0;
        hi[i + 1] = hi0;
    }
    
    for (int i = n - 1; i >= 0; i--) {
        if (d[i] == 1) lo0--;
        if (d[i] == -1) {
            d[i] = 0;
            if (lo[i] <= lo0 - 1) {
                lo0--;
                d[i] = 1;
            }            
        }
    }

    for(auto &x: d) cout << x << ' ';
    cout << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    string s;
    cin >> testcase;

    while(testcase--) {
        sol();
        tt++;
    }
    return 0;
}

