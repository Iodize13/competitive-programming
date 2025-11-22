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
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }
    
    vector<int> ch(n);
    rep(i,1,n) {
        if (a[i] * 2 > a[i - 1]) ch[i] = 1;
    }

    int cnt = 0, ans = 0;
    rep(i,0,n) {
        if (ch[i]) cnt++;
        else {
            ans += max(0LL, cnt - k + 1);
            cnt = 0;
        }
    }
    ans += max(0LL, cnt - k + 1);

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

