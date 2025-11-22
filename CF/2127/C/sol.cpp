#include<bits/stdc++.h>
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

int tt = 1;

int n, m, k;
string s;

void sol() {
    cin >> n >> m;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
    }

    vector<pair<int, int>> c(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].second;
        if (a[i].first > a[i].second) swap(a[i].first, a[i].second);
        c[i].second = i;
        // c[i].first = abs(a[i] - b[i]);
    }

    sort(all(a));
    int mn = LLONG_MAX;
    int st = 0;
    bool ud = 0;
    for (int i = 1; i < n; i++) {
        if (a[i].first - a[i - 1].second < mn) {
            st = i;
            mn = a[i].first - a[i - 1].second;
            ud = 0;
        }
    }
    int ans = 0;
    // cerr << st << '\n';
    ans = abs(a[st].second - a[st].first) + abs(a[st - 1].first - a[st - 1].second);
    swap(a[st].first, a[st - 1].first);
    // cerr << ans << '\n';
    ans = max(ans,abs(a[st].second - a[st].first) + abs(a[st - 1].first - a[st - 1].second));
    swap(a[st].first, a[st - 1].first);
    swap(a[st].second, a[st - 1].first);
    // cerr << ans << '\n';
    ans = max(ans,abs(a[st].second - a[st].first) + abs(a[st - 1].first - a[st - 1].second));
    // cerr << ans << '\n';
    for (int i = 0; i < n; i++) {
        if (i == st - 1 || i == st) continue;
        ans += abs(a[i].first- a[i].second);
    }
    // for (int i = 0; i < n - 2; i++) {
    //     ans += c[i].first;
    // }

    // int p = c[n - 1].second;
    // int q = c[n - 2].second;
    // ans += max(abs(a[p] - b[p]) + abs(a[q] - b[q]), max(abs(a[p] - a[q]) + abs(b[q] - b[p]),
    // max(abs(a[p] - b[q]) + abs(a[q] - b[p]), abs(a[p] - b[q]) + abs(b[p] - a[q]))));

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

