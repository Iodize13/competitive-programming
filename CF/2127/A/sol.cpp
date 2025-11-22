#include<bits/stdc++.h>
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

int tt = 1;

int n, m, k;
string s;

void sol() {
    cin >> n; 
    vector<int> a(n);
    int st = -1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] != -1) st = a[i];
    }
    // cerr << st << '\n';

    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            cout << "NO\n";
            return;
        }
    }

    if (st == -1) {
        for (int i = 1; i < n; i++) {
            if (a[i] != a[i - 1]) {
                cout << "NO\n";
                return;
            }
        }
    } else {
        for (int i= 0; i < n; i++) {
            if (a[i] == -1) continue;
            if (a[i] != st) {
                cout << "NO\n";
                return;
            }   
        }
    }

    cout << "YES\n";
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int testcase(1);
    cin >> testcase;
    while(testcase--) {
        sol();
        tt++;
    }
    return 0;
}

