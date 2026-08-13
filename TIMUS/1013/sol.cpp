#include "bits/stdc++.h"
 
using namespace std;
 
#define int long long
#define sz(x) (int)(x).size()
 
int M;

int mul (int a, int b) {
	int ans = 0;
	while (b) {
		if (b & 1) ans = (ans + a) % M;
		b >>= 1;
		a <<= 1;
		a %= M;
	}
	return ans;
}

struct matrix {
	int mat[2][2];
	matrix friend operator *(const matrix &a, const matrix &b) {
		matrix c;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				c.mat[i][j] = 0;
				for (int k = 0; k < 2; k++) {
					c.mat[i][j] = (c.mat[i][j] + mul(a.mat[i][k], b.mat[k][j]) % M) % M;
				}
			}
		}
		return c;
	}
};

matrix matpow(matrix base, int n) {
	matrix ans{ {
		{1, 0},
		{0, 1}
	} };
	while (n) {
		if (n & 1)
			ans = ans*base;
		base = base*base;
		n >>= 1;
	}
	return ans;
}

void solve() {
	int N, K; cin >> N >> K >> M;
	matrix A{ {
		{ (K - 1) % M	, (K - 1) % M	},
		{ 1				, 0				}
	} };
	cout << matpow(A, N).mat[0][0] << '\n';
}
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}
