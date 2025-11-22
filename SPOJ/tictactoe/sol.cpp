#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <set>
#include <map>
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

int tt = 1, n, m;
string s;

void sol();
void init();
map<string, bool> vis;

int32_t main() {
    send help

    init();
    int testcase(1);
    cin >> testcase;

    while(testcase--) {
        sol();
        tt++;
    }
    return 0;
}

void sol() {
    s = "";
    rep(i,0,3) {
        string x;
        cin >> x;
        s += x;
    }

    cout << (vis.count(s) ? "yes" : "no") << '\n';
}

void init() {
    string t = ".........";
    queue<pair<string, bool> > que;
    que.push({t, 0});

    auto check = [&](string c) {
        vi colx(3), rowx(3);
        vi colo(3), rowo(3);
        rep(i,0,3) {
            colx[i] += c[i] == 'X';
            colx[i] += c[3 + i] == 'X';
            colx[i] += c[6 + i] == 'X';
            colo[i] += c[i] == 'O';
            colo[i] += c[3 + i] == 'O';
            colo[i] += c[6 + i] == 'O';
        }

        rep(i,0,3) {
            rowx[i] += c[3 * i] == 'X';
            rowx[i] += c[3 * i + 1] == 'X';
            rowx[i] += c[3 * i + 2] == 'X';
            rowo[i] += c[3 * i] == 'O';
            rowo[i] += c[3 * i + 1] == 'O';
            rowo[i] += c[3 * i + 2] == 'O';
        }

        bool ok = false;
        rep(i,0,3) {
            ok |= rowx[i] == 3;
            ok |= rowo[i] == 3;
            ok |= colo[i] == 3;
            ok |= colx[i] == 3;
        }

        ok |= (c[0] == 'O' && c[4] == 'O' && c[8] == 'O') || (c[2] == 'O' && c[4] == 'O' && c[6] == 'O');
        ok |= (c[0] == 'X' && c[4] == 'X' && c[8] == 'X') || (c[2] == 'X' && c[4] == 'X' && c[6] == 'X');
        return ok;
    };

    while (!que.empty()) {
        auto cur = que.front().first;
        auto to = que.front().second;
        que.pop();
        if (vis[cur]) continue;
        vis[cur] = 1;
        dbg(cur);
        if (check(cur)) {
            dbg("test");
            continue;
        }
        rep(i,0,9) {
            if (cur[i] == '.') {
                cur[i] = to ? 'O' : 'X';
                que.push({cur, (to ^ 1)});
                cur[i] = '.';
            }
        }
    }
}
