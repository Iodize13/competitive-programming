#include<bits/stdc++.h>
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

int tt = 1;

int n, m;
string s;

void sol() {
    int l, r;
    cin >> n >> l >> r;
    vector<int> ans(n);
    bool ok = true;
    for (int i = 1; i <= n; i++) {
        if ((r / i) * i >= l) ans[i - 1] = (r / i) * i;
        else ok = false;
    }

    if (!ok) {
        cout << "NO\n";
        return;
    }
    
    cout << "YES\n";
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

