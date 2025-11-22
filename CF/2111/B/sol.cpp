#include<bits/stdc++.h>

using namespace std;

struct cube {
	int w, h, l;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> n;
	vector<cube> v(m);
	for (int i = 0; i < m; i++) 
		cin >> v[i].w >> v[i].l >> v[i].h;

	set<int> se;
	for (int i = 1, i <= n; i++) {
		se.insert(i);
	}
	for (int i = 0; i < m; i++) {
		set<int> sc = se;
		if (v[i].w > v[i].l) swap(v[i].l, v[i].w);
		auto it = se.begin();
		int cw = v[i].w, cl = v[i].l ,ch  =v[i].h;
		if (*prev(se.end(), 1) > cw) {
			cout << 0;
			break;
		}
		if (se.size() > 1) {
			it = se.upper_bound(min(cw, ch)) - 1;
			cw -= *it;
			se.erase(it);
		}
	}
}
