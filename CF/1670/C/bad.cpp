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
#define f first
#define s second

#define dbg(...) {cerr << "[ " #__VA_ARGS__ << " ]: "<< __VA_ARGS__ << '\n';}

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;

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
int n, m, k;

void sol() {
    cin >> n;
    vector<vector<int> > p(2, vector<int> (n));
    vector<bool> used(n);
    vector<int> a(n), b(n),d(n);
    rep(to,0,2) {
        rep(i,0,n) {
            int x;
            cin >> x;
            --x;
            if (to) {
                b[i] = x;
            } else {
                a[i] = x;
            }
            p[to][x] = i;
        }
    }

    for (auto &x: d) {
        cin >> x;
        x--;
    }


    const int mod = (int)1e9 + 7;

    int ans = 1;
    RollbackUF uf(n);
    rep(i,0,n) {
        if (d[i] != -1) {
            used[uf.find(d[i])] = 1;
        }
        if (used[a[i]]) used[uf.find(a[i])] = 1;
        if (used[b[i]]) used[uf.find(b[i])] = 1;
        // dbg("Here");
        if (!uf.join(a[i], b[i]) && a[i] != b[i] && !used[uf.find(a[i])] && !used[uf.find(b[i])]) {
            if (d[i] == -1) {
                // dbg(i);
                // dbg(d[i]);
                ans = ans * 2LL;
                ans %= mod;
            }
        }
        //     int ind = i;
        //     bool ok = true;
        //     vector<pair<int, int> > cha;
        //     vector<pair<int, int> > chb;
        //     do {
        //         if (d[ind] != 0) ok = false;
        //         chb.push_back({ind, b[ind]});
        //         cha.push_back({ind, a[ind]});
        //         ind = p[1][a[ind]];
        //     } while (ind != i);

        //     rep(j,0,sz(chb)) {
        //         if (ok) d[chb[j].f] = chb[j].s;
        //         else d[cha[j].f] = cha[j].s;
        //     }

        //     if (ok && a[i] != b[i]) {
        //         ans = ans * 2LL;
        //         ans %= mod;
        //     }
        // }
    }

    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt = 1, testcase(1);
    string s;
    cin >> testcase;

    while(testcase--) {
        sol();
        tt++;
    }
    return 0;
}

