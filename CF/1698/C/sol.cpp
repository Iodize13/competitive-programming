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
    for (auto &x: a)
        cin >> x;

    sort(all(a));
    int cntn = 0;
    int cntp = 0;
    map<int, int> mp;
    for (auto &x: a) {
        if (x < 0) cntn++;
        else if (x > 0) cntp++;
        mp[x]++;
    }

    if (n < 5) {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (!mp[a[i] + a[j] + a[k]]) {
                        // cerr << a[i] << ' ' << a[j] << ' ' << a[k] << '\n';
                        // cerr << "ctes\n";
                        cout << "NO\n";
                        return;
                    }
                }
            }
        }

        cout << "YES\n";
        return;
    }
    if (cntn == 1 && cntp == 1 && a[0] + a[n - 1] == 0) {
        cout << "YES\n";
        return;
    } else if (cntp + cntn <= 1) {
        cout << "YES\n";
        return;
    }

    cout <<  "NO\n";
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

