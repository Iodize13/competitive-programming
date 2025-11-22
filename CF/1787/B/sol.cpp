#include<bits/stdc++.h>
#define int long long
#define all(x) (x).begin(), (x).end()

using namespace std;

void sol() {
    int n;
    cin >> n;
    vector<pair<int, int>> factor;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            int e = 0;
            while (n % i == 0) {
                n /= i;
                e++;
            }
            factor.push_back(make_pair(i, e));
        }
    }

    if (n > 1)
        factor.push_back(make_pair(n, 1));

    sort(all(factor), [](const pair<int, int> &a, const pair<int, int> &b) {
        return a.second > b.second;
    });
    
    int ans = 0;
    while(!factor.empty()) {
        int cur = 1LL;
        int mul = factor.back().second;
        for (auto &[F, S]: factor) {
            S -= mul;
            cur = cur * F;
        }
        cerr << "dbg:\n";
        // for (auto [F, S]: factor) cout << F << ' ' << S << '\n';
        while (!factor.empty() && factor.back().second == 0) {
            factor.pop_back();
        }
        cur *= mul;
        ans += cur;
    }
    cout << ans << '\n';
}

int32_t main() {
    int tt;
    cin >> tt;
    while(tt--) sol();
}
