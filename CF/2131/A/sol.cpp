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
    for (int i = 0; i < n; i++) {
        cin  >> a[i];
    }

    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    int ans = 0;

    bool ok = false;
    do {
        ok = false;
        for (int i = 0; i < n; i++) {
            if (a[i] > b[i]) {
                ok = true;
                a[i]--;
                break;
            }
        }
        for (int i = 0; i < n; i++) {
            if (a[i] < b[i]) {
                a[i]++;
                break;
            }
        }
        ans++;
    } while (ok);

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

