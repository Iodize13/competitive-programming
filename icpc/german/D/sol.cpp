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
#include <cmath>
using namespace std;

// #pragma GCC optimize("O3,unroll-loops")
#define send {ios_base::sync_with_stdio(false);}
#define ld long double
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

/**
 * Description: Modular arithmetic. Assumes $MOD$ is prime.
 * Source: KACTL
 * Verification: https://open.kattis.com/problems/modulararithmetic
 * Usage: mi a = MOD+5; inv(a); // 400000003
 */

template<int MOD, int RT> struct mint {
	static const int mod = MOD;
	static constexpr mint rt() { return RT; } // primitive root
 	int v; 
 	explicit operator int() const { return v; } 
	mint():v(0) {}
	mint(ll _v):v((ll)(_v%MOD)) { v += (v<0)*MOD; }
	mint& operator+=(mint o) { 
		if ((v += o.v) >= MOD) v -= MOD; 
		return *this; }
	mint& operator-=(mint o) { 
		if ((v -= o.v) < 0) v += MOD; 
		return *this; }
	mint& operator*=(mint o) { 
		v = (ll)((ll)v*o.v%MOD); return *this; }
	friend mint pow(mint a, ll p) { assert(p >= 0);
		return p==0?1:pow(a*a,p/2)*(p&1?a:1); }
	friend mint inv(mint a) { assert(a.v != 0); return pow(a,MOD-2); }
	friend mint operator+(mint a, mint b) { return a += b; }
	friend mint operator-(mint a, mint b) { return a -= b; }
	friend mint operator*(mint a, mint b) { return a *= b; }
};
using mi = mint<(int)1e9+7, 5>;
using vmi = vector<mi>;

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

/**
 * Description: 1D point update and range query where \texttt{cmb} is
 	* any associative operation. \texttt{seg[1]==query(0,N-1)}.
 * Time: O(\log N)
 * Source: 
	* http://codeforces.com/blog/entry/18051
	* KACTL
 * Verification: SPOJ Fenwick
 */

template<class T> struct SegTree { // cmb(ID,b) = b

	const T ID{}; T cmb(T a, T b) { return {a.first+b.first, a.second + b.second}; } 
	int n; vector<T> seg;
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

int tt = 1, n, m;
string s;

void sol();

int32_t main() {
    send help

    int testcase(1);

    while(testcase--) {
        sol();
        tt++;
    }
    return 0;
}

void sol() {
    int q;
    ld p0;
    cin >> n >> q >> p0;
    p0 = 1.L - p0;
    const mi N = (int)1e6;
    dbg(p0 * 1e6);
    // cerr << type(1e6) << '\n';
    mi p = (int)round(p0 * 1e6L);
    dbg((int)p);
    p = p * inv(N);
    dbg((int)inv(N));
    dbg((int)p);
    SegTree<pair<mi, mi> > seg;
    seg.init(n);
    mi te = 100;
    dbg((int)inv(mi(100)));
    dbg((int)inv(te));
    while(q--) {
        char t;
        cin >> t;
        if (t== '+') {
            int B, X;
            mi b, x;
            cin >> B >> X;
            X--;
            x = X;
            b = B;
            auto [F, S] = seg.query(X,X);
            seg.upd(X, {F + b * pow(p, X), S + b * inv(pow(p, X))}); // can be addition instead
            // seg.upd(X, {b * pow(p, X), b * inv(pow(p, X))}); // can be addition instead
            // st.insert({x, mmul(b, mpow(N - p0))});
        } else if (t == '-') {
            int B, X;
            mi b, x;
            cin >> B >> X;
            X--;
            x = X;
            b = B;
            auto [F, S] = seg.query(X,X);
            seg.upd(X, {F - b * pow(p, X), S - b * inv(pow(p, X))}); // can be addition instead
            // seg.upd(X, {0,0});
        } else {
            int X;
            cin >> X; 
            X--;
            mi l = seg.query(0, X).se * pow(p, X);
            dbg((int)seg.query(0, X).se);
            dbg((int)pow(p, X));
            mi r = seg.query(X + 1, n - 1).fi * inv(pow(p, X));
            dbg((int)seg.query(X + 1, n - 1).fi);
            dbg((int)inv(pow(p,X)));
            dbg((int)l);
            dbg((int)r);
            int ans = (int)(l + r);
            cout << ans << '\n';
        }
    }
}
