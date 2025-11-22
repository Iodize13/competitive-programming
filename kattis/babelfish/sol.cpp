#include<bits/stdc++.h>
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;
int n, m, k;

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt = 1, testcase(1);
    string s;

    bool ok = false;
    map<string, string> mp;
    while(getline(cin, s)) {
        if (s == "") {
            ok = true;
            continue;
        }
        if (ok) {
            if (mp.count(s)) cout << mp[s] << '\n';
            else cout << "eh\n";
        }
        else {
            auto it = s.find(' ');
            assert(it != string::npos);
            mp[s.substr(it + 1)] = s.substr(0, it);
        }
    }
    return 0;
}

