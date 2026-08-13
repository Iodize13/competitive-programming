#include "bits/stdc++.h"
 
using namespace std;
 
#define int long long
#define sz(x) (int)(x).size()
 
int M;
struct matrix {
	int mat[2][2];
	matrix friend operator *(const matrix &a, const matrix &b) {
		matrix c;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				c.mat[i][j] = 0;
				for (int k = 0; k < 2; k++) {
					c.mat[i][j] = (c.mat[i][j] + (__int128_t)a.mat[i][k] * b.mat[k][j] % M) % M;
				}
			}
		}
		return c;
	}
};

void solve() {
	int N, K; cin >> N >> K >> M;
	matrix A{{
			 { (K - 1) % M	, (K - 1) % M	},
			 { 1			, 0				}
			}};
	matrix ans{{
				 {1, 0},
				 {0, 1}
				 }};
	matrix j = A;
	for (int i = N; i > 0; i>>=1, j = j * j) {
		if (i & 1) ans = ans * j;
	}
	cout << ans.mat[0][0] << '\n';
}
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}
