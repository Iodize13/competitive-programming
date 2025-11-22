#include<bits/stdc++.h>
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

int tt = 1;

int n, m;
string s;

void sol() {
    int k;
    cin >> n >> m >> k;
    k -= 2;
    if (n == 1) {
        if (m > 0 || k < 0) {
            cout << "NO\n";
            return;
        } else {
            cout << "YES\n";
            return;
        }
    } 
        
    if (m > (n * (n - 1)) / 2) {
        cout << "NO\n";
    } else if (m == (n * (n - 1)) / 2) {
        if (k >= 1) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    } else if (m >= n - 1) {
        if (k >= 2) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    } else {
        cout << "NO\n";
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

