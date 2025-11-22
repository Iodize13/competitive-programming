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
    for (int i = 0 ; i <n ; i++) {
        cin >> a[i];
    }
    vector<int> c(all(a));

    vector<int> b(n);
    for (int i = 0; i < n; i++ ) {
        cin >> b[i];
    }

    for (int i = n - 2; i >= 0; i--) {
        if (a[i] == b[i]) continue;
        else {
            if ((a[i] ^ a[i + 1]) == b[i]) {
                a[i] = a[i] ^ a[i + 1];
                continue;
            }
            a[i] ^= c[i + 1];
        }
    }

    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            cout << "NO\n";
            return;
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

