#include<bits/stdc++.h>
#define ll long long
#define int long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    int tmp = 0;
    int i;
    for (i = 1; tmp < n;i++) {
        string s = to_string(i); 
        bool ok = true;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == '0' || s[j] == '8') {
                ok = false;
                break;
            }
        }
        if (!ok) continue;
        tmp++;
    }
    --i;
    cout << i << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
