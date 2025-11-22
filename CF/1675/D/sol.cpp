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
    vector<int> par(n);
    vector<int> is_leave(n, 1);
    for (auto &x: par) {
        cin >> x;
        x--;
    }

    for (int i = 0; i < n; i++) {
        is_leave[par[i]] = 0;
    }

    vector<int> vis(n);
    vector<vector<int> > ans;
    for (int i = 0; i < n; i++) {
        if (!is_leave[i]) continue;
        vector<int> temp;
        for (int j = i; !vis[j]; j = par[j]) {
            temp.push_back(j);
            vis[j] = 1;
        }
        ans.push_back(temp);
    }

    if (n == 1) {
        cout << "1\n" << "1\n" << "1\n\n";
        return;
    }

    cout << sz(ans) << '\n';
    for (auto &y: ans) {
        reverse(all(y));
        cout << sz(y) << '\n';
        for (auto &x: y) {
            cout << x + 1<< ' ';
        }
        cout << '\n';
    }

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

