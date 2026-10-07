// #pragma GCC optimize("O3,unroll-loops")
#include "bits/stdc++.h"

using namespace std;

// #define int long long
#define sz(x) (int)(x).size()



void solve() {
	int N; // cin >> N;
	scanf("%d", &N);
	vector<array<int, 4> > query(N);
	for (int i = 0; i < N; i++) {
		char S[5]; scanf("%s", S);
		// fprintf(stderr, "case: 2\n");
		scanf("%d", &query[i][0]);
		// fprintf(stderr, "case: 3\n");
		--query[i][0];
		query[i][1] = i;
		query[i][2] = strcmp(S, "PUSH") == 0;
		if (query[i][2])
			scanf("%d", &query[i][3]);
		// fprintf(stderr, "case: 4\n");
		// for (auto &x: query[i]) {
		// 	fprintf(stderr, "%d ", x);
		// 	fflush(stdout);
		// }
	}
	// fprintf(stderr, "case: 5");
	// fflush(stdout);
	sort(query.begin(), query.end());
	vector<int> ans(N, -1);
	stack<int> st;
	for (int i = 0; i < N; i++) {
		auto &[bucket, id, isPush, B] = query[i];
		if (i != 0 && bucket != query[i - 1][0]) {
			while (!st.empty())
				st.pop();
		}
		if (isPush) {
			st.push(B);
		} else {
			ans[id] = st.top();
			st.pop();
		}
	}
	// fprintf(stderr, "case: 6");
	for (auto &x: ans)
		if (x != -1) 
			printf("%d\n", x);
}

int32_t main() {
	// ios_base::sync_with_stdio(false);
	// cin.tie(nullptr);

    solve();
}

