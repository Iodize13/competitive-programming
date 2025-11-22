#include<bits/stdc++.h>
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

int tt = 1;

int n, m;
string s;

void sol() {
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) 
        cin >> a[i];

    int st = -1;
    for (int i = 1; i < n; i++) {
        if (a[i - 1] == 0 && a[i] == 1) {
            st = i;
        }
    }

    if (a[n - 1] == 0) {
        for (int i = 1; i <= n + 1; i++) {
            cout << i << " \n"[i == n + 1];
        }
    } else if (a[0] == 1) {
        cout << n + 1 << ' ';
        for (int i = 1; i <= n; i++) {
            cout << i << " \n"[i == n];
        }
    } else {
        for (int i = 1; i <= n; i++) {
            if (st + 1 == i) {
                // cerr << "when: " << i << '\n';
                cout << n + 1 << ' ';
            }
            cout << i << ' ';
        }
        cout << '\n';
    }
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

