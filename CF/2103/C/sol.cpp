#include<bits/stdc++.h>

using namespace std;

void runcase() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++) 
		cin >> a[i];
		
	int cnX = 0;
	int cnM = 0;
	bool ok = false;
	bool fok = false;
	bool ans = false;
	int en = -1;
	for (int i = 0; i < n; i++) {
		if (cnM > cnX && a[i] <= k) {
			ok = true;
			cnM = 0;
			cnX = 0;
			en = i;
		}
		if (a[i] <= k) ++cnM;
		else ++cnX;
		if (ok) {
			if ((cnM > cnX && n - 2 == i)|| (cnM == cnX && cnM != 0)) {
				ans = true;
				break;
			}
		} else {
			if ((cnM > cnX && n - 3 == i)|| (cnM == cnX && cnM != 0)) {
				ok = true;
				cnM = 0;
				cnX = 0;
				en = i;
			}
		}
	}

	cnM = 0;
	cnX = 0;
	bool ok2 = false;
	for (int i = n - 1; i >= 0 ; i--) {
		if (cnM > cnX && a[i] <= k) {
			ok2 = true;
			cnM = 0;
			cnX = 0;
		}
		if (a[i] <= k) ++cnM;
		else ++cnX;
		if (ok2) {
			if ((cnM > cnX && 1 == i)|| (cnM == cnX && cnM != 0)) {
				ans = true;
				break;
			}
		} else {
			if ((cnM > cnX && 2 == i)|| (cnM == cnX && cnM != 0)) {
				ok2 = true;
				cnM = 0;
				cnX = 0;
			}
		}
	}

	cnM = 0;
	cnX = 0;
	bool ok3 = false;
	for (int i = n - 1; i > en ; i--) {
		if (cnM > cnX && a[i] <= k) {
			ok3 = true;
			cnM = 0;
			cnX = 0;
		}
		if (a[i] <= k) ++cnM;
		else ++cnX;
		if (ok3) {
			if ((cnM > cnX && en + 1 == i)|| (cnM == cnX && cnM != 0)) {
				ans = true;
				break;
			}
		} else {
			if ((cnM > cnX && en + 2 == i)|| (cnM == cnX && cnM != 0)) {
				ok3 = true;
				cnM = 0;
				cnX = 0;
			}
		}
	}

	cerr << "dbg: " << ok3 << ", en: " << en << '\n';
	if (ok && ok3) ans = true;
	cout << (ans ? "YES" : "NO") << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while(t--) {
		runcase();
	}
}

