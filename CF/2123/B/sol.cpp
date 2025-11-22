#include<bits/stdc++.h>

using namespace std;

void runcase() {
	long long n, j ,k;
	cin >> n >> j >> k;
	long long a[n];
	for (int i = 0; i < n; i++) {
	cin >> a[i];
	}
	
	bool ok = false;
	if (a[j - 1] == *max_element(a, a + n)) {
		ok = true;	
	} else if (k >= 2){
		ok = true;
	}
	cout << (ok ? "YES" : "NO") << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while(t--) {
		runcase();
	}
}

