#include<bits/stdc++.h>
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

int tt = 1;

const int mod = 32768;

int n, m, k;
string s;

void sol() {
    cin >> n;
    vector<int> a(n);
    for (auto &x: a)
        cin >> x;

    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        while (a[i] % mod) {
            int cnt = 0;
            int b = 0;
            int temp = a[i];
            while (!(temp & 1)) {
                b++;
                temp >>= 1;
            }

            while (temp & 1) {
                cnt++;
                temp >>= 1;
            }

            if (cnt >= (1 << b)) {
                ans[i] += (1 << b);
                a[i] += (1 << b);
            } else {
                a[i] *= 2;
                ans[i]++;
            }
        }
    }

    for (auto &x: ans) cout << x << ' ';
    cout << '\n';
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

