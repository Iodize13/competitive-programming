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
    int n, m;
    cin >> n >> m;
    vector<vi> g(n+2, vi(m+2));
    rep(i,0,n+2) {
        rep(j,0,m+2) {
            cin >> g[i][j];
        }
    }
    auto og = g;

    auto valid = [&](int r, int c) {
        return r >= 0 && r < n + 2 && c >= 0 && c < m + 2;
    };

    int dx8[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int dy8[8] = { 0,  1, 1, 1, 0,-1,-1, -1};
    auto del = [&](int r, int c) {
        g[r][c]--;
        rep(i,0,8) {
            int ny = r + dy8[i];
            int nx = c + dx8[i];
            if (valid(ny, nx)) g[ny][nx]--;
        }
    };

    vector<vector<char> > res(103, vector<char>(103,'.'));
    rep(i,0,n+2) {
        rep(j,0,m+2) {
            if (g[i][j] == 1 && valid(i + 1, j + 1)) {
                del(i+1, j+1);
                res[i+1][j+1]='X';
            }
        }
    }

    bool ok = true;
    rep(i,0,n+2) if (res[i][0] == 'X' || res[i][m+1] == 'X') ok = false;
    rep(j,0,m+2) if (res[0][j] == 'X' || res[n+1][j] == 'X') ok = false;


    vector<vi> check(n+2, vi(m+2));
    auto add = [&](int r, int c) {
        check[r][c]++;
        rep(i,0,8) {
            int ny = r + dy8[i];
            int nx = c + dx8[i];
            check[ny][nx]++;
        }
    };
    if (!ok) {
        cout << "impossible\n";
        return;
    }
    rep(i,0,n+2) {
        rep(j,0,m+2) {
            if (res[i][j] == 'X') add(i,j);
        }
    }

    // rep(i,0,n+2) {
    //     rep(j,0,m+2) cerr << check[i][j];
    //     cerr << '\n';
    // }

    rep(i,0,n+2) {
        rep(j,0,m+2) {
            if (og[i][j] != check[i][j]) {
                ok = false;
            }
        }
    }

    if (!ok) {
        cout << "impossible\n";
        return;
    }

    rep(i,1,n+1) {
        rep(j,1,m+1) {
            cout << res[i][j];
        }
        cout << '\n';
    }
}
