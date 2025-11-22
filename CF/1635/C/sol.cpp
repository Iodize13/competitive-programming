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

    if (is_sorted(all(a))) {
        cout << 0 << '\n';
        return;
    }
    if (a[n - 2] > a[n - 1]) {
        cout << -1 << '\n';
        return;
    } 
    if (a[n - 2] - a[n - 1] <= a[n - 2]) {
        cout << n - 2 << '\n';
        for (int i = 0; i < n - 2; i++) {
            cout << i + 1 << ' ' << n - 1 << ' ' << n << '\n';
        }
    } else {
        cout << -1 << '\n';
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

