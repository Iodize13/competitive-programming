#include<bits/stdc++.h>
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

int tt = 1;

int n, m;
string s;

void sol() {
    cin >> n >> m;
    if (n > m || (n % 2 == 0 && m % 2 == 1)) {
        cout << "NO\n";
        return;
    }
    
    cout << "YES\n";
    if (n % 2 == 0) {
        for (int i = 0; i < n - 2 ;i++) {
            cout << 1 << ' ';
        }
        cout << (m - n + 2) / 2 << ' ';
        cout << (m - n + 2) / 2 << ' ';
        cout << '\n';
    } else {
        for (int i = 0; i < n - 1 ;i++) {
            cout << 1 << ' ';
        }
        cout << (m - n + 1) << ' ';
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

