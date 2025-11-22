#include<bits/stdc++.h>
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

int tt = 1;

int n, m, k;
string s;

void sol() {
    cin >> s;
    int cnt = 0;
    int st = 0;
    for (int i = sz(s) - 1; i >= 0; i--) {
        if (s[i] == '0') cnt++;
        else {
            st = i;
            break;
        }
    }

    for (int i = st - 1; i >= 0; i--) {
        if (s[i] != '0') cnt++;
    }

    cout << cnt << '\n';
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

