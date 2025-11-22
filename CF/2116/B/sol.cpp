#include<bits/stdc++.h>

using namespace std;

const long long MOD = 998244353;

long long ma[(long long)1e5 + 9];

void runcase() {
	long long n;
	cin >> n;
	vector<long long> a(n);
	vector<long long> b(n);
	for (long long i = 0 ; i < n; i++) 
		cin >> a[i];

	for (long long i = 0; i < n; i++) 
		cin >> b[i];

	vector<long long> ans(n);
	vector<long long> wh(n);
	long long mxA = -INT_MAX;
	long long mxB = -INT_MAX;
	for (long long i = 0, idA = - 1, idB = -1; i < n; i++) {
		if (a[i] > mxA) {
			idA = i;
			mxA = a[i];
		}
		if (b[i] > mxB) {
			idB = i;
			mxB = b[i];
		}
		if (mxB == mxA) {
			if (b[i - idA] > a[i - idB]) {
				ans[i] = (ma[a[idA]] + ma[b[i - idA]]) % MOD;
			wh[i] = idA;
			} else {
				ans[i] = (ma[a[i - idB]] + ma[b[idB]]) % MOD;
			wh[i] = i - idB;
			}
		} else if (mxB > mxA) {
			ans[i] = (ma[a[i - idB]] + ma[b[idB]]) % MOD;
			wh[i] = i - idB;
		} else {
			ans[i] = (ma[a[idA]] + ma[b[i - idA]]) % MOD;
			wh[i] = idA;
		}
	}

	for (auto X: ans) 
		cout << X << ' ';
	cout << '\n';

	for (auto X: wh) 
		cerr << X << ' ';
	cerr << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	ma[0] = 1;
	for (long long i = 1; i < 1e5 + 9 ;i++) {
		ma[i] = (2LL * ma[i - 1]) % MOD;
	}
	while(t--) {
		runcase();
	}
}

