#include<bits/stdc++.h>
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

int tt = 1;

int n, m, k;
string s;

void sol() {
    cin >> n >> k >> s;
    int cnto = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') cnto++;
    }

    // cerr << "cnt: " << cnto << '\n';
    int mn = abs(cnto - n + cnto) / 2;
    int mx = n / 2 - cnto % 2;
    // cerr << "mn: " << mn << '\n';
    // cerr << "mx: " << mx << '\n';
    if (!(k <= mx && k >= mn)) {
        cout << "NO\n";
        return;
    }
    cout << (k % 2 == mn % 2 ? "YES" : "NO") << '\n';
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

