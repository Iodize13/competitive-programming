#include<bits/stdc++.h>
#define ll long long
#define int long long

using namespace std;

ll euclid(ll a, ll b, ll &c, ll &e) {
	if (!b) return c = 1, e = 0, a;
	ll d = euclid(b, a % b, e, c);
	return e -= a/b * c, d;
}

const ll mod = (int)1e9 + 7;
struct Mod {
	ll x;
	Mod(ll xx) : x(xx) {}
	Mod operator+(Mod b) { return Mod((x + b.x) % mod); }
	Mod operator-(Mod b) { return Mod((x - b.x + mod) % mod); }
	Mod operator*(Mod b) { return Mod((x * b.x) % mod); }
	Mod operator/(Mod b) { return *this * invert(b); }
	Mod invert(Mod a) {
		ll e, y, g = euclid(a.x, mod, e, y);
		assert(g == 1); return Mod((e + mod) % mod);
	}
	Mod operator^(ll e) {
		if (!e) return Mod(1);
		Mod r = *this ^ (e / 2); r = r * r;
		return e&1 ? *this * r : r;
	}
};


void sol() {
    int n;
    cin >> n;
    vector<Mod> a;
    for (int i = 0; i < n; i++) {
        int H;
        cin >> H;
        a.push_back(Mod(H));
    }

    Mod sum = 0;
    Mod cur = 0;
    Mod cnt = 0;
    int j = 1;
    for (int i = n - 1; i > 0; i--) {
        cur = cur + a[i];
        sum = sum + cur * a[i - 1];
        cnt = cnt + j;
        j++;
    }
    cout << (sum / cnt).x << '\n';
}

int32_t main() {
    int tt;
    cin >> tt;
    while(tt--) sol();
}
