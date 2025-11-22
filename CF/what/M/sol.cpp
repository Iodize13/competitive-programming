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

int tt = 1, n;
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

bool dp[101][101][101];

void sol() {
    map<array<int, 3>, bool> mp;
    cin >> n;
    for (int i = 1; i <= 100; i++) {
        if (i == n) continue;
        rep(j,1,101) {
            if (i == j || j == n) continue;
            rep(k,1,101) {
                if (k == j || k == i || k == n) continue;
                int ans = i;
                bool ok = true;
                rep(l, 0, 4) {
                    int tmp = ans;
                    if (l == 0) {
                        tmp += j;
                    } else if(l == 1) {
                        tmp -= j;
                    } else if (l == 2) {
                        tmp *= j;
                    } else if (l == 3 && ans % j == 0) {
                        tmp /= j;
                    }
                    if (tmp == n) ok = false;
                    rep(m, 0,6) {
                        int cur = tmp;
                        if (m == 0) {
                            cur += k;
                        } else if (m == 1) {
                            cur -= k;
                        } else if (m == 2) {
                            cur *= k;
                        } else if (m == 3 && cur % k == 0) {
                            cur /= k;
                        } else if (m ==4) {
                            cur = k - cur;
                        } else if (m == 5 && k % cur == 0) {
                            cur = k / cur;
                        }
                        if (cur == n) ok = false;
                    }
                }
                array<int, 3> tmp0 = {i, j, k};
                sort(all(tmp0));
                auto [i0,i1,i2] = tmp0;
                dp[i0][i1][i2] |= !ok;
            }
        }
    }
    rep(i,1,101) {
        if (i == n) continue;
        rep(j,1,101) {
            if (j <= i || j == n) continue;
            rep(k,1,101) {
                if (k <= j || k == n) continue;
                if (!dp[i][j][k]) {
                    cout << i << ' ' << j << ' ' << k << '\n';
                    return;
                }
            }
        }
    }
}

