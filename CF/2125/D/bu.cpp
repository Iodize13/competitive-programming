#include<bits/stdc++.h>
#define int long long
#define ll long long
#define all(x) (x).begin(), (x).end()

using namespace std;

// int prev = 0;
int n, m;

ll euclid(ll a, ll b, ll &c, ll &e) {
	if (!b) return c = 1, e = 0, a;
	ll d = euclid(b, a % b, e, c);
	return e -= a/b * c, d;
}

const ll mod = 998244353;
struct Mod {
	ll v;
	Mod(ll xx) : v(xx) {}
	Mod operator+(Mod b) { return Mod((v + b.v) % mod); }
	Mod operator-(Mod b) { return Mod((v - b.v + mod) % mod); }
	Mod operator*(Mod b) { return Mod((v * b.v) % mod); }
	Mod operator/(Mod b) { return *this * invert(b); }
	Mod invert(Mod a) {
		ll x, y, g = euclid(a.v, mod, x, y);
		assert(g == 1); return Mod((v + mod) % mod);
	}
	Mod operator^(ll e) {
		if (!e) return Mod(1);
		Mod r = *this ^ (e / 2); r = r * r;
		return e&1 ? *this * r : r;
	}
};

Mod di(1);

struct node {
    Mod l, r, p, q;

	node(Mod a,Mod c,Mod d,Mod e) : l(a), r(c), p(d), q(e) {}
    bool operator<(node o) const {
        return l.v < o.l.v;
    }
};
vector<node> b;

Mod f(int idx) {
    cerr << "idx: " << idx << '\n';
    if (idx != -1 && b[idx].r.v == m - 1) {
        // cerr << b[idx].p << '\n';
        cerr << (b[idx].p / b[idx].q).v;
        return (b[idx].p / b[idx].q) / ((b[idx].q - b[idx].p) / b[idx].q) * di;
    }
    Mod ret(0);
    int prev = -1;
    if (idx != -1) prev = b[idx].r.v;
    int j = 1;
    while(idx + j < n && b[idx + j].l.v <= prev + 1) {
        if (b[idx + j].l.v < prev + 1) {
            j++;
            continue;
        }
        ret = ret + f(idx + j);
        // ret = ret + f(b[j].r);
        cerr << "ret: " << ret.v << '\n';
        j++;
    }
    if (idx != -1) ret = (ret * (b[idx].p / b[idx].q)) / ((b[idx].q - b[idx].p) / b[idx].q);
    return ret;
}

void sol() {
    cin >> n >> m;
    b.clear();
    di = Mod(1);
    // j = 0;
    for (int i = 0; i < n; i++) {
        int a, c, d, e;
        cin >> a >> c >> d >> e;
            //cin >> b[i].l >> b[i].r >> b[i].p >> b[i].q;
            a--;
            c--;
//        b[i].l--;
//        b[i].r--;
        node tmp =node(Mod(a), Mod(c), Mod(d), Mod(e));
        b.push_back(tmp);
    }

    for (int i = 0; i < n; i++) {
        cerr << b[i].p.v << ' ' << b[i].q.v << '\n';
        cerr << ((b[i].q - b[i].p) / b[i].q).v << '\n';
        cerr << "Mod: " << (((b[i].q - b[i].p)  /b[i].q)).v << '\n';;
        di = di * (((b[i].q - b[i].p)  /b[i].q));
    }
    cerr << "di.v: " << di.v << endl;
    sort(all(b));
    // cerr << (Mod(1) / Mod(2)).v << '\n';
    cout << f(-1).v << '\n';
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int testcase(1);//  cin >> testcase;
    while(testcase--) {
        sol();
    }
    return 0;
}
