#include<bits/stdc++.h>

using namespace std;

long long n;
void runcase() {
	cin >> n;
	vector<int> a(n);
	vector<int> used(n, 0);
	for (int i = 0; i< n; i++) {
		a[i] = i;
	}
	
	bool ans = true;
	for (int i = 0; i < n; i++) {
		if (used[i]) continue;
		used[i] = 1;
		bool ok = false;
		for (int j = 0 ; j < n; j++) {
			if (used[j]) continue;
			if (ok) break;
			if ((i + j) % 4 == 3) {
				used[j] = 1;
				cerr << "dbg: " << i << ", j: " << j << '\n';
				ok = true;
			}
		}
		if (!ok) {
			ans = false;
			cout << "Alice" << '\n';
			return;
		}
	}
	cout << "Bob" << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while(t--) {
		runcase();
	}
}

