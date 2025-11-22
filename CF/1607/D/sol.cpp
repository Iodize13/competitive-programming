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
        vector<pair<char, int> > a(n);
        for (auto &x: a)
            cin >> x.second;

        cin >> s;
        for (int i = 0 ; i < n; i++) {
            a[i].first = s[i];
        }

        sort(all(a));

        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (a[i].first == 'B') {
                if (a[i].second < i + 1) ok = false;
            } else {
                if (a[i].second > i + 1) ok = false;
            }
        }

        cout << (ok ? "YES" : "NO") << '\n';
    };

    while(testcase--) {
        sol();
        tt++;
    }
    return 0;
}

