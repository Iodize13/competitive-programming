#include<bits/stdc++.h>
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

int tt = 1;

int n, m;
string s;

void sol() {
    cin >> n >> m;
    int k = 0;
    k = n / 2;
    int H = (k + 1) * k * 2;
    vector<int> a(n);
    iota(all(a), 1);
    // if (tt == 1524) {
    //     string ret = to_string(n) + "," +to_string(m);
    //     cout << ret << '\n';
    // }
    if (m % 2 == 1) {
        cout << "NO\n";
        return;
    }
    if (n % 2 == 0) {
        // cerr << "H: " << H - k * 2<< '\n';
        if (m > H - k * 2) {
            cout << "NO\n";
            return;
        }
    } else {
        // cerr << "H: " << H << '\n';
        if (m > H) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
    int prev = n - 1;
    for (int i = 0; i < n / 2; i++) {
        // cerr << "i: " << i << ", abs(min(prev - 1, m  /2)): " << abs(min(prev - 1, m  /2)) << '\n';
        // if (min(prev - 1, m / 2 + i) <= i) break;
        // int r = abs(min(prev - 1, m / 2 + i) - i);
        if (prev <= i) {
            cerr << "i: " << i << '\n';
            break;
        }
        // cerr << "m: " << m << '\n';
        while ((prev - i) * 2 > m) {
            --prev;
        }
        // cerr << "prev: " << prev << '\n';
        swap(a[i], a[prev]);
        m -= (prev - i) * 2;
        // cerr << "r: "  << r << '\n';
        prev = prev - 1;
//         cerr << "m: " << m << '\n';
//         cerr << "prev: " << prev << '\n';
    }

    for (int i = 0; i < n; i++) cout << a[i] << " \n"[i == n - 1];
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

