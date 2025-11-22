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
    vector<int> a(n);
    vector<int> b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < m; i++)
        cin >> b[i];

    sort(all(b));
    if (b[0] < 2 * a[0]) a[0] = b[0] - a[0];
    for (int i = 1; i < n; i++) {
        int l = -1, r = m - 1;
        while(r - l > 1) {
            int mid = midpoint(l, r);
            if (b[mid] >= a[i - 1] + a[i]) {
                r = mid;
            } else {
                l = mid;
            }
        }
        // cerr << "a[i - 1]: " << a[i - 1] << '\n';
        // cerr << "i: " << i << '\n';
        // cerr << "l: " << l << ", b[l]: " << b[r] << '\n';
        if (a[i] == a[i - 1]) continue;
        if (a[i] < a[i - 1]) a[i] = b[r] - a[i];
        else if (b[r] - a[i] < a[i] && b[r] - a[i] >= a[i - 1]) a[i] = b[r] - a[i];
        if (a[i - 1] > a[i]) {
            cout << "NO\n";
            return;
        }
    }

    cout << (is_sorted(all(a)) ? "YES" : "NO") << '\n';
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

