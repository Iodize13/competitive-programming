#include<bits/stdc++.h>
#define int long long
#define sz(x) (int)(x).size()

using namespace std;

void sol() {
    int n;
    cin >> n;
    vector<int> ta;

    for (int i = 0; i * i <= 2 * (n - 1); i++) ta.push_back(i * i);

    cerr << "ta:\n";
    for (auto X: ta) cerr << X << ' ';

    vector<int> ans(n, -1);
    int j = sz(ta) - 1;
    for (int i = n - 1; i >= 0; i--) {
        if (ans[i] != -1) continue; 
        while(!(ta[j] - i >= 0 && ta[j] - i < n) || (ta[j] - i >= 0 && ans[ta[j] - i] != -1)) j--;
        ans[i] = ta[j] - i;
        ans[ta[j] - i] = i;
        cerr << "dbg: " << ans[i] << '\n';
    }

    for (auto X: ans) cout << X << ' ';
    cout << '\n';
}

int32_t main() {
    int tt;
    cin >> tt;
    while(tt--) sol();
}
