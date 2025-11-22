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
        vector<int> a(n);
        for (auto &x: a)
            cin >> x;

        // if (tt == 40) {
        //     string ret = to_string(n) + ":";
        //     for (auto &x: a) ret += to_string(x) + ",";
        //     cout << ret << '\n';
        // }
        vector<int> parity(2);
        for (auto &x: a) {
            x %= 2;
            parity[x]++;
        }

        for (auto &x: a) //cerr << x << ' ';
        //cerr << '\n';

        if (abs(parity[0] - parity[1]) > 1) {
            cout << "-1\n";
            return;
        }
        vector<int> b(all(a));

        int ans = 0;
        int to = (parity[1] == parity[0] ? a[0] : parity[1] > parity[0]);
        //cerr << "to: " << to << '\n';
        for (int i = 0, j = 0; i < n; i++) {
            j = max(j, i);
            if (a[i] == to) {
                to ^= 1;
                continue;
            }
            while (j < n && a[j] != to) {
                j++;
            }

            // //cerr << "i: " << i << ", j: " << j << '\n';

            ans += j - i;
            if (j < n) swap(a[i], a[j]);
            to ^= 1;
        }
        if (parity[1] == parity[0]) {
            int cur = 0;
            to = !b[0];
            for (int i = 0, j = 0; i < n; i++) {
                j = max(j, i);
                if (b[i] == to) {
                    to ^= 1;
                    continue;
                }
                while (j < n && b[j] != to) {
                    j++;
                }

                cur += j - i;
                if (j < n) swap(b[i], b[j]);
                to ^= 1;
            }
            ans = min(cur, ans);
        }

        cout << ans << '\n';
    };

    while(testcase--) {
        sol();
        tt++;
    }
    return 0;
}

