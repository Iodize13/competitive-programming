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
    vi best(n);
    auto is_palindrome = [&](string x) {
        return equal(all(x) - sz(x) / 2, x.rbegin());
    };

    int cur = 0;
    string first = "";
    int ind = 0;
    rep(i,0,n) {
        for (int j = n - 1; j >= i; j--) {
            if (s[i] == s[j] && is_palindrome(s.substr(i, j - i + 1))) {
                best[i] = j - i + 1;
                if (best[i] > cur) {
                    cur = best[i];
                    first = s.substr(i, best[i]);
                    ind = i;
                }
                break;
            }
        }
    }

    auto dfs = [&](auto &&self, int l, int r) {
        if (r < l) return;
        if (r == l) {
            a.push_back(s.substr(l, 1));
            return;
        }
        int mx = 0;
        int ind0 = l;
        string t = "";
        rep(i,l,r+1) {
            // cerr << "i: " << i << '\n';
            if (best[i] + i - 1 > r) {
                best[i] = 1;
                for (int j = r; j >= i; j--) {
                    if (s[i] == s[j] && is_palindrome(s.substr(i, j - i + 1))) {
                        best[i] = j - i + 1;
                        break;
                    }
                }
            }
            if (best[i] > mx) {
                mx = best[i];
                t = s.substr(i, best[i]);
                ind0 = i;
            }
        }

        //cerr << "l: " << l << ", ind0: " << ind0 << ", r: " << r << '\n';
        self(self, l, ind0 - 1);
        //cerr << "dbg:\n";
        //for (auto &x: a) cerr <<x << ' ';
        //cerr << '\n';
        dbg(best[ind0]);
        //cerr << "l: " << l << ", ind0: " << ind0 << ", r: " << r << '\n';
        dbg(t);
        a.push_back(t);
        self(self, ind0 + best[ind0], r);
    };
    dfs(dfs, 0, ind - 1);
    //cerr << "dbg 0:\n";
    //for (auto &x: a) cerr <<x << ' ';
    //cerr << '\n';
    a.push_back(first);
    //cerr << "dbg 1:\n";
    //for (auto &x: a) cerr <<x << ' ';
    //cerr << '\n';
    dbg(cur);
    dbg(ind);
    dbg(best[ind]);
    dfs(dfs, ind + best[ind], n - 1);

    cout << sz(a) << '\n';
    for (auto &x: a) cout << x << ' ';
    cout << '\n';
}

