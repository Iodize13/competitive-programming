#include "bits/stdc++.h"
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
			////cerr << "Call gen_factorial you dope" << endl;
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

    int tt;
    cin >> tt;
    while(tt--) sol();
}

void sol() {
    int n, m;
    cin >> n >> m;  

    vector<vector<char> > g(n, vector<char>(m));
    rep(i,0,n) 
        rep(j,0,m) cin >> g[i][j];

    if (n == m && n == 1) {
        cout << 0 << '\n';
        return;
    }

    vector<vector<int> > vis(n, vector<int>(m));

    auto valid = [&](int r, int c) {
        return r >= 0 && r < n && c >= 0 && c < m;
    };

    int ans = 0;
    int dx4[4] = {-1, 0, 1, 0};
    int dy4[4] = {0, 1, 0, -1};
    string ds = "LDRU";
    auto dfs = [&](auto&& self, int r, int c) -> int {
        vis[r][c] = 2;
        rep(i,0,4) {
            if (g[r][c]==ds[i]) {
                int ny = r + dy4[i];
                int nx = c + dx4[i];
                if (!valid(ny, nx) || vis[ny][nx] == 1) {
                    ////cerr << r << ", " << c << '\n';
                    vis[r][c] = 1;
                    return vis[r][c];
                }
                if (vis[ny][nx] == 2) {
                    ans++;
                    // cerr << r << ", " << c << '\n';
                    return 2;
                }
                vis[r][c] = self(self, ny, nx);
                ans += vis[r][c] == 2;
                return vis[r][c];
            }
        }
        // cerr << r << ", " << c << '\n';
        ans++;
        return 2;
    };

    rep(i,0,n) {
        rep(j,0,m) {
            if (!vis[i][j] && g[i][j] != '?') {
                ////cerr << i << ", " << j << '\n';
                dfs(dfs,i,j);
            }
        }
    }
    // rep(i,0,n) {
    //     rep(j,0,m) {
    //         cerr << vis[i][j];
    //     }
    //     cerr << '\n';
    // }

    dbg(ans);
    rep(i,0,n) {
        rep(j,0,m) {
            if (!vis[i][j]) {
                rep(k,0,4) {
                    int ny = i + dy4[k];
                    int nx = j + dx4[k];
                    if (valid(ny, nx) && (vis[ny][nx] == 2 || g[ny][nx] == '?')) {
                        ans++;
                        break;
                    }
                }
            }
        }
    }

    cout << ans << '\n';
    // we don't dfs on ?. the left over are added to ans.
    // wrong look at the first tc.
}

// don't be lazy on debugging
