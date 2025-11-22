#include<bits/stdc++.h>
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

int tt = 1;

int n, m;
string s;

void sol() {
    int ta, k; 
    cin >> n >> k >> ta;
    if (ta < k || ta > (n - 1) * k) {
        cout << "NO\n";
        return;
    }

    bool ok = false;
    int cnt = -1;
    for (int i = 0; i <= k; i++) {
        int r = k - cnt - 1;
        if (i * (n - 1) <= ta && i + (ta - i * (n - 1)) >= k && ta - (r + i * (n - 1)) <= n - 1) {
            cnt = i;
            ok = true;
            break;
        }
    }
    cerr << "cnt: " << cnt;
    cerr << "k: " << k << '\n';

    if (!ok) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    int tg = 1;
    int last = 1;
    for (int i = 0; i < cnt; i++) {
        if (tg) {
            last = n;
        } else {
            last = 1;
        }
        cerr << "last: ";
        cout << last << ' ';
        tg ^= 1;
    }
    if (cnt != k) {
        int r = k - cnt - 1;
        if (last == n) {
            last -= ta - (r + cnt * (n - 1));
        } else {
            last += ta - (r + cnt * (n - 1));
        }
        cout << last << ' ';
        for (int i = 0; i < r; i++) {
            if (last == n) {
                last -= 1;
            } else {
                last += 1;
            }
            cout << last << ' ';
        }
    }
    cout << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int testcase(1);
    while(testcase--) {
        sol();
        tt++;
    }
    return 0;
}

