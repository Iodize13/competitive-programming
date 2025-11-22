#include<bits/stdc++.h>
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;
int n, m, k;

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt = 1, testcase(1);
    string s;
    cin >> testcase;

    auto sol = [&]() {
        cin >> n;        
        vector<int> a(n);
        for (auto &x: a)
            cin >> x;

        for (int i = 0, x = 2; i < n; i++, x = lcm(x, i + 2)) {
            if (a[i] % x == 0) {
                cout << "NO\n";
                return;
            }
            if (x == 219060189739591200) break;
        }

        cout << "YES\n";
    };

    while(testcase--) {
        sol();
        tt++;
    }
    return 0;
}

