#include<bits/stdc++.h>

using namespace std;

using ll = long long;

int n;

void runcase() {
	cin >> n;
	cerr << "n: " << n << '\n';
	map<int, int> ma;
	int mx = -INT_MAX;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		ma[x]++;
		mx = max(mx, x);
	}

	int prev = -1;
	int cnt2 = 0;
    int en = INT_MAX;
    ll sum = 0;
    bool ok = true;
	for (auto [key, val]: ma) {
		if (ok && key != prev + 1) {
			cerr << "key: " << key << ", prev: " << prev << '\n';
            en = prev;
            ok = false;
		}
        if (ok) {
            cerr << "ma: " << key << '\n';
            sum += val - 1;
            cnt2++;
            prev = key;
        } else {
            sum += val;
        }
	}
	cerr << "cnt2: " << cnt2 << '\n';
    vector<int> ans(n + 1);
    ++cnt2;
    int k = n, j =1;
    for (k = n ; j <= cnt2 && k >= 0; k--, j++) {
        ans[k] = j;
    }
    int ae = 0;
    int mb[(int)1e6 + 2];
    memset(mb, 0, sizeof mb);
    for (auto [key, val]: ma) {
        if (key > en) break;
        mb[val]++;
    }
    // for (auto [key, val]: ma) cerr << "key: " << key << ", val: " << val << '\n';
    int pref[(int)1e6 + 2];
    pref[0] = 1;
    for (int i = 1; i <= n + 1; i++) {
        pref[i] = pref[i - 1] + mb[i];
    }
    // for (int i = 0; i <= 10; i++) { cerr << pref[i] << ' '; } cerr << '\n';
    cerr << "sum: " << sum << '\n';
    for (int i = 1; i <= (int)sum - 1; i++) {
        cerr << "enter\n";
        ans[i] = pref[i];
    }
    ans[0] = 1;
    // cerr << "en : " << en << '\n';
    for (auto X: ans) {
        cout << (en == INT_MAX && ma.size() == 1 ? 1 : X) << ' ';
    }
    cout << '\n';
    // for (auto [key, val]: ma) {
    //     if (key > prev || k == 0) break;
    //     if (val <= k) ans[k] = 
    // }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while(t--) {
		runcase();
	}
}

