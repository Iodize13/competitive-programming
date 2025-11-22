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
    vector<int> a(n);
    for (auto &x: a)
        cin >> x;

    vector<int> mp(n + 1);
    vector<int> b;
    for (auto &x: a) {
        if (x < n + 1 && !mp[x]) mp[x] = 1;
        else {
            b.push_back(x);
        }
    }

    sort(all(b));
    bool ok = true;
    for (int i = 1, j = 0; i <= n; i++) {
        if (mp[i]) continue;
        if (b[j] - i > i) j++;
        else {
            ok = false;
        }
    }

    cout << (ok ? sz(b): -1) << '\n';
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

