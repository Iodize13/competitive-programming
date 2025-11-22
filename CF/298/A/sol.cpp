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
    cin >> s;
    int l = count(all(s), 'L');
    int r = count(all(s), 'R');
    int st, last;
    bool ok = false;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'L') {
            if (!ok) {
                st = i;
                ok = true;
            }
            last = i;
        }
    }
    if (l && r) {
        cout << last + 1<< ' ' << st + 1<< '\n';
    } else if (l) {
        cout << last + 1 << ' ' << st << '\n';
    } else {
        ok = false;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'R') {
                if (!ok) {
                    st = i;
                    ok = true;
                }
                last = i;
            }
        }
        cout << st + 1 << ' ' << last + 2 << '\n';
    }
    
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

