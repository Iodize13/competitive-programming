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
        int a, b;
        cin >> a >> b;

        if (a < b) swap(a, b);
        int ta = a, tb = b;
        vector<vector<int>> mn(2, vector<int>(2));
        for (int aob = 0; aob < 2; aob++) {
            int to = aob;
            for (int mx = 0; mx < 2; mx++) {
                a = ta;
                b = tb;
                if (mx) {
                    swap(a, b);
                }
                for (int i = 0; i < ta + tb; i++) {
                    if (!to) {
                        if (a > 0) {
                            a--;
                            if (mx) mn[aob][mx]++;
                        } else {
                            if (!mx)mn[aob][mx]++;
                        }
                    } else {
                        if (b > 0) {
                            b--;
                            if (mx) mn[aob][mx]++;
                        } else {
                            if (!mx)mn[aob][mx]++;
                        }
                    }
                    to ^= 1;
                }
            }
        }

        // for (int i = 0; i < 2; i++) {
        //     for (int j = 0; j < 2; j++) {
        //         cout << mn[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        set<int> st;
        for (int i = mn[0][0]; i <= mn[1][1]; i+=2) {
            st.insert(i);
        }
        for (int i = mn[1][0]; i <= mn[0][1]; i+=2) {
            st.insert(i);
        }

        cout << sz(st) << '\n';
        for (auto &x: st) cout << x << ' ';
        cout << '\n';
    };

    while(testcase--) {
        sol();
        tt++;
    }
    return 0;
}

