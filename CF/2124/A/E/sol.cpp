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
typedef pair<int, int> pii;

int n, m, k;

void sol() {
    cin >> n;
    vi pref(n), suf(n);
    for (auto &x: pref) {
        cin >> x;
    }

    for (auto &x: suf) {
        cin >> x;
    }

    if (pref[n-1] != suf[0]) {
        cout << "NO\n";
        return;
    }

    rep(i,0,n - 1) {
        if (gcd(pref[i], suf[i+1]) != suf[0]) {
            cout << "NO\n";
            return;
        }
    }

    rep(i,0,n-1) {
        if (pref[i] % pref[i+1] != 0 || suf[i+1] % suf[i] != 0) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
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

