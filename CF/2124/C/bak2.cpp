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
int n, m, k;

void sol() {
    cin >> n;
    vector<int> b(n);
    int g = 0;
    for (auto &x: b) {
        cin >> x;
        g = gcd(g, x);
    }
    
    for (auto &x: b) x /= g;

    {
     bool ok = true;
     rep(i,0,n-1) if (b[i+1] % b[i] != 0) ok = false;

     if (ok) {
         cout << 69 << '\n';
         return;
     }
    }

    int x = 0;
    rep(i,0,n - 1) {
        if (b[i+1] % b[i] != 0) {
            x = max(x, b[i] / gcd(b[i + 1], b[i]) << '\n';
            return;
        }
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

