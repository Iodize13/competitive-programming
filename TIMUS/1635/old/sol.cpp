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
const int inf = (int)2e18 + 5;

int32_t main() {
    send help

    solve();
}

void solve() {
    string s;
    cin >> s;
    int n = sz(s);
    vector<string> a;
    vi dp(n+1, inf), p(n+1);
    dp[0] = 0;
    auto is_palindrome = [&](string x) {
        return equal(all(x) - sz(x) / 2, x.rbegin());
    };

    rep(i,1,n+1) {
        rep(j,0,i) {
            if (s[i-1] == s[j] && is_palindrome(s.substr(j, i - j))) {
                if (1 + dp[j] < dp[i]) {
                    dp[i] = 1 + dp[j];
                    p[i] = j;
                }
            }
        }
    }

    cout << dp[n] << '\n';
    int cur = n;
    while (cur) {
        a.push_back(s.substr(p[cur], cur - p[cur]));
        cur = p[cur];
    }
    reverse(all(a));
    for (auto &x: a) cout << x << ' ';
    cout << '\n';
}

