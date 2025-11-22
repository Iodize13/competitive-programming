#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <deque>
#include <stack>
#include <cstdint>
#include <ctime>
#include <cassert>
#include <string>
#include <cstring>
#include <bitset>
#include <array>
using namespace std;

// #pragma GCC optimize("O3,unroll-loops")
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
#define fi first
#define se second
#define int long long
#define ll long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < (b); ++i)

#ifdef LOCAL
#define dbg(...) {cerr << "LINE " << __LINE__ << " -> " << #__VA_ARGS__ << ": " << __VA_ARGS__ << endl;}
#else
#define dbg(...) 42
#endif

typedef vector<int> vi;
typedef pair<int, int> pii;
const int mod = (int)1e9 + 7;

namespace modop {

    ll madd(ll a, ll b) {
        return (a + b) % mod;
    }
    ll msub(ll a, ll b) {
        return (((a - b) % mod) + mod) % mod;
    }
    ll mmul(ll a, ll b) {
        return ((a % mod) * (b % mod)) % mod;
    }
    ll mpow(ll base, ll exp) {
        ll res = 1;
        while (exp) {
            if (exp % 2 == 1){
                res = (res * base) % mod;
            }
            exp >>= 1;
            base = (base * base) % mod;
        }
        return res;
    }
    ll minv(ll base) {
        return mpow(base, mod - 2);
    }
    ll mdiv(ll a, ll b) {
        return mmul(a, minv(b));
    }

    const ll FACTORIAL_SIZE = 1.1e6;
    ll fact[FACTORIAL_SIZE], ifact[FACTORIAL_SIZE];
    bool __factorials_generated__ = 0;
    void gen_factorial(ll n) {
        __factorials_generated__ = 1;
        fact[0] = fact[1] = ifact[0] = ifact[1] = 1;

        for (ll i = 2; i <= n; i++) {
            fact[i] = (i * fact[i - 1]) % mod;
        }
        ifact[n] = minv(fact[n]);
        for (ll i = n - 1; i >= 2; i--) {
            ifact[i] = ((i + 1) * ifact[i + 1]) % mod;
        }
    }
    ll nck(ll n, ll k) {
        if (!__factorials_generated__) {
            cerr << "Call gen_factorial you dope" << endl;
            exit(1);
        }
        if (k < 0 || n < k) return 0;
        ll den = (ifact[k] * ifact[n - k]) % mod;
        return (den * fact[n]) % mod;
    }
}
using namespace modop;

struct RollbackUF {
    vi e; vector<pii> st;
    RollbackUF(int n) : e(n, -1) {}
    int size(int x) { return -e[find(x)]; }
    int find(int x) { return e[x] < 0 ? x : find(e[x]); }
    int time() { return sz(st); }
    void rollback(int t) {
        for (int i = time(); i --> t;)
            e[st[i].first] = st[i].second;
        st.resize(t);
    }
    bool join(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (e[a] > e[b]) swap(a, b);
        st.push_back({a, e[a]});
        st.push_back({b, e[b]});
        e[a] += e[b]; e[b] = a;
        return true;
    }
};

void sol();

int32_t main() {
    send help

        sol();
}

void sol() {
    int n;
    cin >> n;
    vector<pii> g(n);
    rep(i,0,n) {
        cin >> g[i].first >> g[i].second;
    }

    vector<pii> bac(n);
    rep(i,0,n) {
        cin >> bac[i].first >> bac[i].second;
    }

    sort(all(g));
    sort(all(bac));
    int h = abs(g[n-1].second - g[0].second);
    int w = abs(g[n-1].first - g[0].first);
    int nh = abs(bac[n-1].second - bac[0].second);
    int nw = abs(bac[n-1].first - bac[0].first);
    int S = -1;
    bool ok = true;
    if (h != 0) {
        if (nh % h != 0) {
            dbg("test");
            ok = false;
        }
        else S = nh / h;
    }
    // need to handle case where S doesn't initialize because h == 0. for w
    if (w != 0) {
        if (nw % w != 0) {
            dbg("test");
            ok = false;
        } else {
            if (S == -1) {
                S = nw / w;
            } else if (nw / w != S) {
                dbg(S);
                dbg(nw/w);
                ok = false;
            }
        }
    }
    if (!ok) {
        dbg("test");
        cout << -1 << '\n';
        return;
    }
    dbg(S);
    if (S == -1) S = 1;
    int ofx = bac[0].first - g[0].first * S;
    int ofy = bac[0].second - g[0].second * S;
    rep(i,0,n) {
        g[i].fi *= S;
        g[i].fi += ofx;
        g[i].se *= S;
        g[i].se += ofy;
    }

    rep(i,0,n) {
        if (g[i].fi != bac[i].fi || g[i].se != bac[i].se) ok = false;
    }

    if (S > (int)2e9 || !((ofx <= (int)4e18 && ofx >= (int)-4e18) &&
                          (ofy <= (int)4e18 && ofy >= (int)-4e18))) ok = false;
    if (!ok) {
        cout << -1 << '\n';
        return;
    }
    cout << (S == -1 ? 1 : S) << ' ' << ofx << ' ' << ofy << '\n';
    // may need to check for -4e18
}

