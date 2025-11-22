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
#define each(a,x) for (auto& a: x)
#define rsz resize
#define pb push_back

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

template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;
template<class C, bool directed> struct Dijkstra {
	int SZ; V<C> dist; 
	V<V<pair<int,C>>> adj;
	void init(int _SZ) { SZ = _SZ; adj.clear(); adj.rsz(SZ); }
	void ae(int u, int v, C cost) {
		adj[u].pb({v,cost}); if (!directed) adj[v].pb({u,cost}); }
	void gen(int st) {
		dist.assign(SZ,numeric_limits<C>::max());
		using T = pair<C,int>; 
        pqg<T> pq; 
		auto ad = [&](int a, C b) {
			if (dist[a] <= b) return;
			pq.push({dist[a] = b,a});
		}; ad(st,0);
		while (sz(pq)) {
			T x = pq.top(); pq.pop(); if (dist[x.s] < x.f) continue;
			each(y,adj[x.s]) ad(y.f,x.f+y.s);
		}
	}
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
    cin >> n >> m;        
    Dijkstra<int, true> g;
    g.init(n);
    vi inc(n), ouc(n);
    rep(i,0,m) {
        int u, v, c;
        cin >> u >> v >> c;
        u--;
        v--;
        g.ae(u, v, -c);
        ouc[u]++;
        inc[v]++;
    }

    int ans = 0;
    vi pos, dest;
    rep(i,0,n) {
        if (inc[i] == 0) pos.push_back(i);
        if (ouc[i] == 0) dest.push_back(i);
    }
    for (auto &x: pos) {
        dbg(x);
        g.gen(x);
        vi dist = g.dist;
        for (auto &y: dest) {
            ans = min(ans, dist[y]);
        }
    }

    cout << -ans << '\n';
}
