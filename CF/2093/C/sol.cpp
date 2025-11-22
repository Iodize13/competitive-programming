#include<bits/stdc++.h>
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

int tt = 1;

int n, m, k;
string s;

void sol() {
    cin >> n >> k;
    if (n == 1) {
        int temp = n;
        for (int i = 0; i < k - 1; i++) {
            n = n * 10 + temp;
        }

        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                cout << "NO\n";
                return;
            }
        }
        cout << (k == 1 ? "NO\n" : "YES\n");
    } else {
        if (k != 1) {
            cout << "NO\n";
            return;
        }
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                cout << "NO\n";
                return;
            }
        }

        cout << (n == 1 ? "NO\n" : "YES\n");
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

