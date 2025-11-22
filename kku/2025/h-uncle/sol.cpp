#include<bits/stdc++.h>
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

void sol() {
    string s;
    cin >> s;
    int n = sz(s);
    string ans = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
    if (n <= 4) {
        while (sz(s) < 4) {
            auto mn = min_element(all(s));
            s.insert(mn, *mn);
            // cerr << "s: " << s << '\n';
        }
        cout << s << '\n';
        return;
    }
    for (int i = 1; i < n; i++) {
        string a = s.substr(0, i);
        reverse(a.begin(), a.end());
        for (int j = 1; j < n && i + j < n; j++) {
            string b = s.substr(i, j);
            reverse(b.begin(), b.end());
            for (int k = 1; k  <n && i + j + k< n; k++) {
                string c = s.substr(i + j, k);
                reverse(c.begin(), c.end());
                string d = s.substr(i + j + k);
                reverse(d.begin(), d.end());
                ans = min(ans, a + b + c + d);
                // cerr << "a: " << a << '\n';
                // cerr << "b: " << b << '\n';
                // cerr << "c: " << c << '\n';
                // cerr << "d: " << d << '\n';
            }
        }
    }
    cout << ans << '\n';
}

// abcd
int32_t main() {
    int t; cin >> t;
    while(t--) sol();
}   
