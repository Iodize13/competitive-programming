#include<bits/stdc++.h>
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

int tt = 1;

int n, m, k;
string s;

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int testcase(1);
    cin >> testcase;
    vector<vector<int> > bit((int)2e5 + 1, vector<int>(32));

    for (int i = 1; i <= (int)2e5; i++) {
        int temp = i;
        int j = 0;
        while(temp) {
            bit[i][j] += (temp & 1);
            temp >>=1 ;
            j++;
        }
    }

    for (int i = 1; i <= (int)2e5; i++) {
        for (int j = 0; j < 32; j++) {
            bit[i][j] += bit[i - 1][j];
        }
    }

    auto sol = [&]() {
        int l, r;
        cin >> l >> r;
        vector<int> a(32);
        for (int i = 0; i < 32; i++) {
            a[i] = (r - l + 1) - (bit[r][i] - bit[l - 1][i]);
        }

        cout << *min_element(all(a)) << '\n';
    };

    while(testcase--) {
        sol();
        tt++;
    }
    return 0;
}

