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
    a[0] = -1;
    if (n % 2 == 1) {
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) a[i] = -1;
            else a[i] = 3;
        }
    } else {
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) a[i] = -1;
            else a[i] = 3;
        }
        a[n - 1] = 2;
    }

    for (auto &X: a) cout << X << ' ';
    cout << '\n';
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

