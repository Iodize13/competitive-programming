#include<bits/stdc++.h>

using namespace std;

void runcase() {
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> b(n);
	for (int i = 0; i < n; i++) 
		cin >> a[i];

	for (int i = 0; i < n; i++)
		cin >> b[i];

	map<int, pair<int, char>> ma;
	for (int i = n - 1; i >= 0; i--) {
		if (a[i] == b[i]) {
			cout << i + 1 << '\n';
			return;
		}
		bool ok = false;
		if (ma.count(a[i])) {
			if (ma[a[i]].second == 'a') {
				ok = true;
			} else {
				if (abs(i - ma[a[i]].first) > 1) ok = true;
			} 
		} else {
			ma[a[i]] = {i, 'a'};	
		}
		if (ma.count(b[i])) {
			if (ma[b[i]].second == 'b') {
				ok = true;
			} else {
				if (abs(i - ma[b[i]].first) > 1) ok = true;
			}
		} else {
			ma[b[i]] = {i, 'b'};	
		}
		if (ok) {
			cout << i + 1 << '\n';
			return;
		}
	}
	cout << 0 << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while(t--) {
		runcase();
	}
}

