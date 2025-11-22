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

    int tt;
    cin >> tt;
    while(tt--) solve();
}

void solve() {
    string s;
    int n;
    char ch;
    cin >> ch >> n;
    ch -= 'a';
    n--;
    auto valid = [&](int r, int c) {
        return r >= 0 && r < 8 && c >= 0 && c < 8;
    };

    int ans = 0;
    const int d8i[] = {-2, -2, -1, 1, 2, 2, 1, -1};
    const int d8j[] = {-1, 1, 2, 2, 1, -1, -2, -2};
    rep(i,0,8) {
        if (valid(ch+d8i[i], n+d8j[i])) ans++;
    }

    cout << ans << '\n';
}

