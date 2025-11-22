#include<bits/stdc++.h>
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < (b); ++i)

using namespace std;
int n, m, k;

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt = 1, testcase(1);
    string s;
    cin >> testcase;

    auto sol = [&]() {
        cin >> n >> k;        
        cout << ((((2LL * n - k + 1LL) * k) / 2) % 2 == 0 ? "YES" : "NO") << '\n';
    };

    while(testcase--) {
        sol();
        tt++;
    }
    return 0;
}

