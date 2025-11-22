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
const int di[4] = {0, 0, -1, 1};
const int dj[4] = {-1, 1, 0, 0};

int32_t main() {
    send help

    solve();
}

void solve() {
    int n;
    cin >> n;
    auto sum_dig = [&](int x) {
        int ret = 0;
        while (x) {
            ret += x % 10;
            x/=10;
        }
        return ret;
    };

    auto check = [&](int x) {
        return sum_dig(x/1000) == sum_dig(x%1000);
    };

    cout << (check(n+1) || check(n-1) ? "Yes" : "No") << '\n';
}

