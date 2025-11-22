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

    int tt;
    cin >> tt;
    while(tt--) sol();
}

void sol() {
    int x;
    cin >> x;
    auto find_len = [&](int c) {
        int tmp = c;
        int cnt = 0;
        while(c) {
            c /= 10;
            cnt++;
        }
        return cnt;
    };
    if ((x * 10 + 1) % (x + 1) == 0) {
        cout << 1 << '\n';
        return;
    }
    // int f = 10;
    // int base = 1;
    // for (int i = 2; i*i <= x; i++) {
    //     if (i > f) {
    //         f *= 10;
    //         base++;
    //     }
    //     if (x % i == 0) {
    //         if ((x * f + i) % (x + i) == 0) {
    //             dbg(x * (int)pow(10, find_len(i)) + i);
    //             dbg(f);
    //             dbg((int)pow(10, find_len(i)));
    //             dbg("1");
    //             cout << i << '\n';
    //             return;
    //         }
    //         int y = (x / i);
    //         if ((x * (int)pow(10, find_len(y)) + y) % (x + y) == 0) {
    //             dbg("2");
    //             cout << y << '\n';
    //             return;
    //         }
    //     }
    // }
    // if ((x * (int)pow(10, find_len(x)) + x) % (2*x) == 0) {
    //     cout << x << '\n';
    //     return;
    // }
    int e = 1;
    rep(i,1,10) {
        e *= 10;
        int z = e - 1;
        if (z - x > 0 && find_len(z - x) == i) {
            cout << z - x << '\n';
            return;
        }
        // int z = (e - 1);
        // for (int j = 2; j * j <= z;j++) {
        //     if (z % j == 0) {
        //         dbg(x - j);
        //         dbg(i);
        //         if (j - x > 0 && find_len(j - x) == i) {
        //             cout << j - x<< '\n';
        //             return;
        //         }
        //         int v = z / j;
        //         if (v - x > 0 && find_len(v - x) == i) {
        //             dbg("case2");
        //             cout << v - x << '\n';
        //             return;
        //         }
        //     }
        // }
    }
}

