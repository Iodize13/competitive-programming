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
#define f first
#define s second
#define int long long
#define ll long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define V vector

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

const int inf = (int)2e18 + 5;

vi len;
vi ar;

template<class T> struct SegTree { // cmb(ID,b) = b
	const T ID = -inf; T cmb(T a0, T b) { 
        // cerr << "a: " << a0 << ", b: " << b << '\n';
        if (a0 == -inf && b == -inf) {
            // dbg("1");
            return -inf;
        }
        if (a0 == -inf && b != -inf) {
            // dbg("2");
            return b;
        }
        if (a0 != -inf && b == -inf) {
            // dbg("3");
            return a0;
        }
        if (len[ar[a0]] >= 2 && len[ar[b]] >= 2) {
            // dbg("4");
            return max(a0, b);
        }
        if (len[ar[a0]] < 2 && len[ar[b]] < 2) {
            // dbg("5");
            return max(a0, b);
        }
        if (len[ar[a0]] < 2 && len[ar[b]] >= 2) {
            // dbg("6");
            return b;
        }
        if (len[ar[a0]] >= 2 && len[ar[b]] < 2) {
            // dbg("7");
            return a0;
        }
    }
	int n; V<T> seg;
	void init(int _n) { // upd, query also work if n = _n
		for (n = 1; n < _n; ) n *= 2; 
		seg.assign(2*n,ID); }
	void pull(int p) { seg[p] = cmb(seg[2*p],seg[2*p+1]); }
	void upd(int p, T val) { // set val at position p
		seg[p += n] = val; for (p /= 2; p; p /= 2) pull(p); }
	T query(int l, int r) {	// zero-indexed, inclusive
		T ra = ID, rb = ID;
		for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
			if (l&1) ra = cmb(ra,seg[l++]);
			if (r&1) rb = cmb(seg[--r],rb);
		}
		return cmb(ra,rb);
	}
	/// int first_at_least(int lo, int val, int ind, int l, int r) { // if seg stores max across range
	/// 	if (r < lo || val > seg[ind]) return -1;
	/// 	if (l == r) return l;
	/// 	int m = (l+r)/2;
	/// 	int res = first_at_least(lo,val,2*ind,l,m); if (res != -1) return res;
	/// 	return first_at_least(lo,val,2*ind+1,m+1,r);
	/// }
};

void sol();

int testcase = 1;
int32_t main() {
    send help

    int tt;
    cin >> tt;
    while(tt--) {
        testcase = 1;
        sol();
    }
}

void sol() {
    int n, q;
    cin >> n >> q;
    ar.clear();
    ar.resize(n);
    for (auto &x: ar) {
        cin >> x;
    }
    len.clear();
    len.resize(n + 2);
    
    SegTree<int> seg;
    seg.init(n + 1);
    vi res(n, -1), p(n, -1);
    rep(i,0,n) {
        int x = seg.query(ar[i] + 1, n);
        if (x == -inf) {
            seg.upd(ar[i], i);
            len[ar[i]]++;
            p[i] = i;
        } else {
            seg.upd(ar[i], i);
            dbg(ar[x]);
            len[ar[i]] = len[ar[x]] + 1;
            if (len[ar[i]] >= 3) {
                dbg(p[x]);
                res[i] = p[x];
            }
            p[i] = x;
        }
        // for (auto &y: len) cerr << y << ' ';
        // cerr << '\n';
    }

    // for (auto &x: res) cerr << x << ' ';
    // cerr << '\n';
    // for (auto &x: seg.seg) cerr << x << ' ';
    // cerr << '\n';
    vi pref(n);
    int mx = res[0];
    rep(i,0,n) {
        mx = max(res[i], mx);
        pref[i] = mx;
        //cerr << pref[i] << " \n"[i+1==n];
    }
    while(q--) {
        int l, r;
        cin >> l >> r;
        if (testcase == 280) {
            string s ="";
            for (auto &x: ar) s += to_string(x) + ',';
            s += ':';
            s += to_string(l) + ',' + to_string(r);
        }
        l--;
        r--;
        testcase++;
        if (pref[r] < l) {
            cout << "YES\n";
            continue;
        }
        cout << "NO\n";
    }
}

