// #pragma GCC optimize("O3,unroll-loops")
#include "bits/stdc++.h"

using namespace std;

#define int long long
#define sz(x) (int)(x).size()



void solve() {
	string T, date;
	getline(cin >> ws, T);
	getline(cin >> ws, date);
	// cerr << "T: " << T << endl;
	// cerr << "date: " << date << endl;
	int S, P; cin >> P >> S;
	// cerr << "P, S: " << P << ' ' << S << endl;
	vector<int> state(P);
	for (int i = 0; i < S; i++) {
		char L; cin >> L;
		// cerr << "L: " << L << '\n';
		string D;
		getline(cin >> ws, D);
		// cerr << "D: " << D << endl;
		int cur = L - 'A';
		if (state[cur] == 1) continue;
		if (D[0] == 'A')
			state[cur] = 1;
		else 
			state[cur] = 2;
	}
	string combineD = "";
	for (int i = 0; i < P; i++) {
		char cur;
		if (state[i] == 0)
			cur = '.';
		else if (state[i] == 1)
			cur = 'o';
		else
			cur = 'x';
		combineD += cur;
	}
	cout << "|" << left << setw(30) << T << "|" << date << "|" << left << setw(13) << combineD << "|\n"
	"+------------------------------+--------+-------------+\n";
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int tt;
	cin >> tt;
	// cerr << "tt: " << tt << endl;
	cout << "+------------------------------+--------+-------------+\n"
			"|Contest name                  |Date    |ABCDEFGHIJKLM|\n"
			"+------------------------------+--------+-------------+\n";
    while (tt--) 
		solve();
}

