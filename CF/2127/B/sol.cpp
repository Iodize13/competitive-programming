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
    cin >> s;
    int bk = 0;
    for (int i = 0; i < n ;i++) {
        bk += s[i] == '#';
    }
    if (bk == 0 || m == 1 || m == n) {
        //cerr << "case bk == 0 } || m == 1 || m == n: " << '\n';
        cout << "1\n";
        return;
    }
    bk = 0;
    int ll = 0;
    for (int i = 0; i < m - 1; i++) {
        bk += s[i] == '#';
        if (s[i] == '#') ll = i;
    }
    int r = 0;
    int last = -1;
    for (int i = n -1; i > m - 1; i--) {
        r += s[i] == '#';
        if (s[i] == '#') last = i;
    }
    // cerr << bk << ' ' << r << ' ' << ll << ' ' << last << '\n';
    if (bk == 0) {
        //cerr << "case bk == 0: " << '\n';
        m--;
        cout << min(m + 1, n - last + 1) << '\n';
        return;
    } else {
        if (r == 0) {
            //cerr << "case r == 0: " << '\n';
            m--;
            // cerr << "test\n";
            cout << min(n - m, ll + 2) << '\n';
            return;
        } else {
            //cerr << "TES\n";
            m--;
            if (ll < n - last - 1) {
                // cerr << "test\n";
                // cerr << m + 1 << ' ' << n - last -1;
                cout << min(m + 1, n - last + 1) << '\n';
                return;
            } else {
                // cerr << "test2\n";
                // cerr << ll + 2 << ' '<< n - m<< '\n';
                cout << min(ll + 2, n - m) << '\n';
            }
            // cout << min(ll + 1, n - last + 1) << '\n';
        }
    }
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

