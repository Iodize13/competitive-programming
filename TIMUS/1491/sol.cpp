// #pragma GCC optimize("O3,unroll-loops")
#include "bits/stdc++.h"

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define dbg(...) 42
#define nl 42
#endif
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
#define f first
#define s second
#define int long long
#define ll long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef vector<int> vi;
typedef pair<int, int> pii;
const int di[4] = {0, 0, -1, 1};
const int dj[4] = {-1, 1, 0, 0};

namespace opt {
    void precomp() {
    }
}



const bool TC = 0;
void solve() {
    int n;
    cin >> n;
    vector<array<int, 3> > co;
    rep(i,0,n+1) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        co.push_back({a, 0, c});
        co.push_back({b, 1, c});
    }

    sort(all(co));
    vector<int> res(n, -1);
    int last = 0;
    int cur = 0;
    bool to = 0;
    int c = 0;
    rep(i,0,sz(co)) {
        if (co[i][0] != last) {
            if (!co[i][1]) {
                // if (c) {
                    // not sure lower bound
                    rep(j,last + 1,co[i][0]) {
                        res[j] = cur;
                    }
                // }
                // do some
            } else {
                rep(j,last+1, co[i][0] + 1) res[j] = cur;
                if (!to) res[last] = cur;
            }
        }
        if (co[i][1]) { // close
                // maybe printf(remember the sync thing) are just better?
            cur -= co[i][2];
            c--;
            to = 1;
        } else {
            cur += co[i][2];
            res[co[i][0]] = cur;
            c++;
            to = 0;
        }
        last = co[i][0];
    }

    rep(i,0,n) {
        cout << (res[i] == -1 ? 0 : res[i]) << " \n"[i+1==n];
    }
}

int32_t main() {
    send help

    opt::precomp();

    int tt = 1;
    if (TC) cin >> tt;
    while (tt--) solve();
}

/// 1 3 5 7
/// last
