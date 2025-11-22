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

template<class F>
int ternSearch(int a, int b, F f) {
	assert(a <= b);
    while (b - a >= 3) {
        int m1 = a + (b - a) / 3;
        int m2 = b - (b - a) / 3;
        int f1 = f(m1);      //evaluates the function at m1
        int f2 = f(m2);      //evaluates the function at m2
        if (f1 < f2)
            a = m1;
        else
            b = m2;
    }
	rep(i,a+1,b+1) if (f(a) > f(i)) a = i; // (B)
	return a;
}


const bool TC = 1;
void solve() {
    int n;
    cin >> n;
    string t;
    cin >> t;
    vi p, q;
    rep(i,0,n) {
        if (t[i] == 'a') p.push_back(i);
        else q.push_back(i);
    }

    // test all a or no a
    auto check = [&](int x) {
        int ret = 0;
        rep(i,0,sz(p)) {
            ret += abs(p[i] - i - x);
        }

        // cerr << "ret: " << ret << '\n';
        return ret;
    };
    auto check0 = [&](int x) {
        int ret = 0;
        rep(i,0,sz(q)) {
            ret += abs(q[i] - i - x);
        }

        // cerr << "ret: " << ret << '\n';
        return ret;
    };
    int ind = ternSearch(0, n - sz(p), check);
    int ind0 = ternSearch(0, n - sz(q), check0);
    // cerr << "ind0: " << ind0 << '\n';
    cout << min(check(ind), check0(ind0)) << '\n';
}

int32_t main() {
    send help

    int tt = 1;
    if (TC) cin >> tt;
    while (tt--) solve();
}

