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
    vector<array<int, 3>> a(n);
    for (int i = 0; i < n ;i++) {
        cin >> a[i][0] >> a[i][1];
        a[i][2] = i + 1;
    }

    // if (tt == 986) {
    //     string ret = to_string(n) + ",";
    //     for (auto &X: a) {
    //         ret+=to_string(X[0])+":"+to_string(X[1])+",";
    //     }
    //     cout << ret << '\n';
    // }
    vector<int> b((int)6e3 + 1);
    vector<int> ans;
    for (int i = 0; i < n ;i++) {
        // cerr << accumulate(b.begin() + a[i][0], b.begin() + a[i][1], 0LL) << ' ' << a[i][1] - a[i][0] + 1  << '\n';
        if (accumulate(b.begin() + a[i][0], b.begin() + a[i][1], 0LL) != a[i][1] - a[i][0]) {
            for (int j = a[i][0]; j < a[i][1]; j++) b[j] = 1;
            ans.push_back(a[i][2]);
        }
    }

    cout << sz(ans) << '\n';
    for (auto &X: ans) cout << X << ' ';
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

