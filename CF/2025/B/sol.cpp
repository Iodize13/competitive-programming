#include<bits/stdc++.h>
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

int tt = 1;

int n, m, k;
string s;

const int mod = (int)1e9 + 7;

void sol() {
    cin >> n;
    vector<int> a(n);
    vector<int> ans((int)1e5 + 1);
    ans[0] = 1;
    for (int i = 1; i < (int)1e5 + 1; i++) {
        ans[i] = (ans[i - 1] * 2)  % mod;
    }
    for (auto &x: a)
        cin >> x;

    vector<int> b(n);
    for (auto &x: b)
        cin >> x;

    for (int i = 0; i < n; i++) {
        if (b[i] == a[i]) {
            cout << "1\n";
            continue;
        }
        cout << ans[b[i]] << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int testcase(1);
    while(testcase--) {
        sol();
        tt++;
    }
    return 0;
}

