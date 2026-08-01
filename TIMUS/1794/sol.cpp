#include "bits/stdc++.h"
 
using namespace std;
 
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
#define int long long
#define sz(x) (int)(x).size()
const int di[4] = {0, 0, -1, 1};
const int dj[4] = {-1, 1, 0, 0};
 
 
 
void solve() {
	int N; cin >> N;
	vector<int> A(N);
	for (auto &x: A) {
		cin >> x;
		--x;
	}
	vector<int> freq(N);
	for (int i = 0; i < N; i++) freq[(A[i] - i + N) % N]++;
	int ans = (N - (max_element(freq.begin(), freq.end()) - freq.begin()) + 1) % N;
	cout << (ans ? ans : N) << '\n';
}
 
int32_t main() {
    send help
    solve();
}
