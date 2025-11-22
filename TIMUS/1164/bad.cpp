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
    int h, w, p;
    cin >> h >> w >> p;
    vector<string> g(h);
    rep(i,0,h) {
        cin >> g[i];
    }

    vector<string> a(p);
    for (auto &x: a) {
        cin >> x;
    }


    auto valid = [&](int r, int c) {
        return r >= 0 && r < h && c >= 0 && c < w;
    };

    // there are no need for bfs to search for word. the length are the same.
    // inside need to be bt. that slow
    bool found = false;
    auto bt = [&](auto &&self, int r, int c, int cur, string wor, vector<bool> &was) {
        if (found) return;
        if (cur == sz(wor) - 1) {
            found = true;
            dbg(wor);
            was[r * w + c] = 1;
            // for (auto x: was) cerr << x << ' ';
            // cerr << '\n';
            return;
        }

        if (was[r * w + c]) return;
        was[r * w + c] = 1;
        rep(dir,0,4) {
            int ni = r + di[dir];
            int nj = c + dj[dir];
            if (!valid(ni, nj) || was[ni * w + nj]) continue;
            if (g[ni][nj] == wor[cur + 1]) {
                self(self, ni, nj, cur+1, wor, was);
                if (found) return;
                // was[ni * w + nj] = 1;
            }
        }

        was[r * w + c] = 0;
    };

    bool done = false;
    // seem problematic
    vector<bool> was0(h * w + 1);
    auto dek = [&](auto &&self, int ind, vector<bool> &was) {
        if (done) return;
        if (ind == p) {
            done = true;
            was0 = was;
            return;
        }

        rep(i,0,h) {
            rep(j,0,w) {
                if (was[i * w + j]) continue;
                if (g[i][j] == a[ind][0]) {
                    // might be too slow? declare it here?
                    vector<bool> nwas = was;
                    found = false;
                    bt(bt, i, j, 0, a[ind], nwas);
                    // go to next word
                    // if (found) self(self, ind+1, was);
                    if (found) {
                        // for (auto x: was) cerr << x << ' ';
                        // cerr << '\n';
                        self(self, ind+1, nwas);
                    }
                }
            }
        }
    };

    dek(dek, 0, was0);
    // if (!done) cout << "wa\n";

    string ans = "";
    rep(i,0,h) {
        rep(j,0,w) {
            if (!was0[i * w + j]) ans += g[i][j];
        }
    }

    sort(all(ans));
    cout << ans << '\n';
}

