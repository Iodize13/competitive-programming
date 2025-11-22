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

void DBG() {
  cerr << "]" << endl;
}
template<class H, class... T> void DBG(H h, T... t) {
  cerr << to_string(h);
  if(sizeof...(t))
    cerr << ", ";
  DBG(t...);
}
// #ifdef LOCAL
// #define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
// #else
// #define dbg(...) 42
// #endif

#define dbg(...) {cerr << "LINE " << __LINE__ << " -> " << #__VA_ARGS__ << ": " << __VA_ARGS__ << endl;}
typedef vector<int> vi;
typedef pair<int, int> pii;

int n, m, k;

void sol() {
    // preprocess
    // sieve find number of multiples for each prime.
    // remove number of multiples by that prime it self.
    // add only this case back (49, 7)
    cin >> n;
    dbg(n);
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt = 1, testcase(1);
    string s;
    cin >> testcase;
    const int N = (int)1e7 + 1;

    vi fac(N + 1);
    vector<bool> is_prime(N+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= N; i++) {
        if (is_prime[i]) {
            for (int j = i; j <= N; j += i) {
                if (j != i) is_prime[j] = false;
                fac[j]++;
            }
        }
    }

    vi res(N + 1);
    rep(i,1,N + 1) {
        res[i] = res[i - 1] + fac[i];
    }

    while(testcase--) {
        cin >> n;
        cout << res[n] << '\n';
        tt++;
    }
    return 0;
}

