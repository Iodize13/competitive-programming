#include<bits/stdc++.h>
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

int tt = 1;

int n, m, k;
string s;

void sol() {
    cin >> n >> k;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mp[x]++;
    }

    int ans = 0;
    int last = -1;
    int sum = 0;
    int cnt = 0;
    for (auto &[x, a]: mp) {
        if (x != last + 1) {
            sum = 0;
            cnt = 0;
        }
        cnt++;
        sum += a;
        if (cnt > k) {
            sum -= mp[x - k];
        }
        last = x;
        ans = max(ans, sum);
    }

    cout << ans << '\n';
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

