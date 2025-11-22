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
    string s;
    getline(cin, s);
    int n = sz(s);
    int ans = 0;
    rep(i,0,n) {
        {
        bool ok = false;
        string let0 = "adgjmpsvy. ";
        rep(j,0,sz(let0)) if (s[i]==let0[j]) ok = true;
        if (ok) ans+=1;
        }
        {
        bool ok = false;
        string let0 = "behknqtwz,";
        rep(j,0,sz(let0)) if (s[i]==let0[j]) ok = true;
        if (ok) ans+=2;
        }
        {
        bool ok = false;
        string let0 = "cfilorux!";
        rep(j,0,sz(let0)) if (s[i]==let0[j]) ok = true;
        if (ok) ans+=3;
        }
    }

    cout << ans << '\n';
}

