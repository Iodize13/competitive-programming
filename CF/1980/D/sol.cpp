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
    vi a0(n);
    for (auto &x: a0) {
        cin >> x;
    }

    vi a1, a2;
    a2 = a1 = a0;

    vi g(n-1);
    rep(i,0,n-1) {
        g[i] = gcd(a0[i], a0[i + 1]);
        //cerr << g[i] << ' ';
    }
    //cerr << '\n';

    rep(i,0,n-2) {
        if (g[i] > g[i+1]) {
            a0.erase(next(a0.begin(), i + 1));
            a1.erase(next(a1.begin(), i + 2));
            a2.erase(next(a2.begin(), i));
            break;
        }
    }

    vi new_g0(n-2), new_g1(n-2), new_g2(n-2);
    rep(i,0,n-2) new_g0[i] = gcd(a0[i], a0[i+1]);
    rep(i,0,n-2) new_g1[i] = gcd(a1[i], a1[i+1]);
    rep(i,0,n-2) new_g2[i] = gcd(a2[i], a2[i+1]);

//     //cerr << "a0: ";
//     for(auto &x: a0) //cerr << x << ' ';
//     //cerr << "\na1: ";
//     for(auto &x: a1) //cerr << x << ' ';
// 
//     //cerr << "\nnew_g0: ";
//     for(auto &x: new_g0) //cerr << x << ' ';
//     //cerr << "\nnew_g1: ";
//     for(auto &x: new_g1) //cerr << x << ' ';
//     //cerr << '\n';
 
    cout << (is_sorted(all(new_g0)) || is_sorted(all(new_g1)) || is_sorted(all(new_g2))? "YES" : "NO") << '\n';
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

