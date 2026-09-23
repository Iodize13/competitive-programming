// #pragma GCC optimize("O3,unroll-loops")
#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<class T>
using ordered_set = tree<T , null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;


#define int long long
#define sz(x) (int)(x).size()



void solve() {
	int N; cin >> N;
	ordered_set<pair<int, int> > A;
	vector<int> ans(N);
	for (int i = 0; i < N; i++) {
		int x, y; cin >> x >> y;
		A.insert({x, y});
		ans[A.order_of_key({x, y})]++;
	}
	for (auto &x: ans) cout << x << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

    solve();
}

