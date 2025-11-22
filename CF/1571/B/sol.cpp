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
        int a, va, c, vc, b;
        cin >> n;
        cin >> a >> va >> c >> vc >> b;
        cerr << "a: " << a << ", va: " << va << ", c: " << c << ", vc:" << vc << ' ' << b << '\n';
        vector<int> v1(101);
        for (int i = a, j = va; i < c; i++) {
            v1[i] = j;
            if (j < vc) j++;
        }
        for (auto &x: v1) cerr << x << ' ';
        cerr << '\n';

        vector<int> v2(101);
        for (int i = c, j = vc; i > a; i--) {
            v2[i] = j;
            if (j > va) j--;
        }
        for (auto &x: v2) cerr << x << ' ';
        cerr << '\n';

        cout << v1[b] - v2[b] + 1 << '\n';
    };

    while(testcase--) {
        sol();
        tt++;
    }
    return 0;
}

