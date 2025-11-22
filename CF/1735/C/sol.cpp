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
    string s;
    cin >> s;
    vector<int> from(27, -1);
    vector<int> to(27, -1);
    vector<int> a(n);
    for (int i = 0; i < n; i++) a[i] = s[i] - 'a';

    RollbackUF uf(26);
    for (int i = 0; i < n; i++) {
        if (from[a[i]] != -1) continue;

        rep(j,0,26) {
            if (to[j] != -1) continue;
            from[a[i]] = j;
            int t = uf.time();
            to[j] = a[i];
            if (!uf.join(j, a[i])) { // join return false == cycle
                if (uf.size(j) == 26) break;
                uf.rollback(t);
                to[j] = -1;
                continue;
            }
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << char('a' + from[a[i]]);
    }
    cout << '\n';
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

