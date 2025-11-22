#include<bits/stdc++.h>
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < (b); ++i)

using namespace std;
int n, m, k;

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt = 1, testcase(1);
    string s;
    cin >> testcase;

    auto sol = [&]() {
        cin >> n;        
        vector<vector<int> > g(n);
        for (auto &x: g) {
            int c;
            cin >> c;
            vector<int> temp(c);
            for (auto &y: temp) cin >> y;

            x = temp;
        }

        vector<pair<int, int> > a(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < sz(g[i]); j++) {
                a[i].first = max(a[i].first, g[i][j] - j + 1);
                a[i].second = sz(g[i]);
            }
        }


        // for (auto &[F, S]: a) cerr << F << ' ' << S << '\n';
        sort(all(a));
        int ans = a[0].first;
        int sum = ans + a[0].second;
        for (int i = 1; i < n; i++) {
            if (sum >= a[i].first) {
            } else {
                ans += a[i].first - sum;
                sum = a[i].first;
            }
            sum += a[i].second;
        }

        cout << ans << '\n';
    };

    while(testcase--) {
        sol();
        tt++;
    }
    return 0;
}

