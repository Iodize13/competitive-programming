// #pragma GCC optimize("O3,unroll-loops")
#include "stdio.h"
#include "stack"
#include "cstring"

using namespace std;

// #define int long long
#define sz(x) (int)(x).size()


stack<int> st[1000];

void solve() {
	int N; // cin >> N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		char S[5]; scanf("%s", S);
		if (strcmp(S, "PUSH") == 0) {
			int A, B;  // cin >> A >> B;
			scanf("%d", &A);
			scanf("%d", &B);
			--A;
			st[A].push(B);
		} else {
			int A; // cin >> A;
			scanf("%d", &A);
			--A;
			// cout << st[A].top() << '\n';
			printf("%d\n", st[A].top());
			st[A].pop();
		}
	}
}

int main() {
	// ios_base::sync_with_stdio(false);
	// cin.tie(nullptr);

    solve();
}


