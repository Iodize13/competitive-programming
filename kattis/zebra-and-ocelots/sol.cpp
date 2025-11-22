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

    auto sol = [&]() {
        cin >> n;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            char x;
            cin >> x;
            ans = ans * 2 + (x == 'O');
        }

        cout << ans << '\n';
    };

    while(testcase--) {
        sol();
        tt++;
    }
    return 0;
}

