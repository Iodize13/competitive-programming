#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <deque>
#include <stack>
#include <cstdint>
#include <bitset>
#include <cstring>
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define ll long long

using namespace std;
int n, m, k;


const int mod = 1'000'000'007;
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

void sol() {
    int r, g;
    cin >> r >> g;
    int hi = r + g, lo = 0;
    while(hi - lo > 1) {
        int mid = midpoint(lo, hi);
        if (((mid + 1) * mid) / 2 <= r + g) {
            lo = mid;
        } else {
            hi = mid;
        }
    }
    // cerr << "lo: " << lo << '\n';

    int total = (lo * (lo + 1)) / 2;
    vector<int> dp(total + 1);
    dp[0] = 1;

    for (int i = min(lo, g); i > 0; i--) {
    // for (int i = 0; i <= min(lo, g); i++) {
        for (int j = 0; j <= total; j++) {
            if (j - i < 0) continue;
            if (j > g || r + i < total) {
                dp[j] = dp[j - 1];
                continue;
            }
            dp[j] = madd(dp[j], dp[j - i]);
        }
    }

    // for (auto &x: dp) cerr << x << ' ';
    // cerr << '\n';

    // int ans = 0;
    // for (int i = 0; i <= total; i++) {
    //     if (i > g) continue;
    //     if (r + i >= total) {
    //         // cerr << "i: " << i << '\n';
    //         ans = madd(ans, dp[i]);
    //     }
    // }

    cout << dp[total] << '\n';
    // find mx hi first. with dp of hi
    // the 1 to mx. find all the possible with chose/not (or think high of 3 how many can be constrct?)
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt = 1, testcase(1);
    string s;

    while(testcase--) {
        sol();
        tt++;
    }
    return 0;
}

