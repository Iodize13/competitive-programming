// #pragma GCC optimize("O3,unroll-loops")
#include "bits/stdc++.h"

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define dbg(...) 42
#endif
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
#define fi first
#define se second
#define int long long
#define ll long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef vector<int> vi;
typedef pair<int, int> pii;
void solve();
int case_num = 0;
const int di[4] = {0, 0, -1, 1};
const int dj[4] = {-1, 1, 0, 0};

int32_t main() {
    send help

    solve();
}

void solve() {
    int n;
    cin >> n;
    if (n >= 1 && n <= 4) {
        cout << "few\n";
    } else if (n >= 5 && n <=9) {
        cout << "several\n";
    } else if (n >= 10 && n <= 19) {
        cout << "pack\n";
    } else if (n >= 20 && n <= 49) {
        cout << "lots\n";
    } else if (n >= 50 && n <= 99) {
        cout << "horde\n";
    } else if (n >= 100 && n <= 249) {
        cout << "throng\n";
    } else if (n >= 250 && n <= 499) {
        cout << "swarm\n";
    } else if (n >= 500 && n <= 999) {
        cout << "zounds\n";
    } else {
        cout << "legion\n";
    }
}

