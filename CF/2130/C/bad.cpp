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

    map<int, int> lp;
    map<int, int> rp;

    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (lp[a[i][0]])
        mp[a[i][0]]++;
        mp[a[i][1]]++;
        ans.push_back(a[i][2]);
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

