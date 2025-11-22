#include<bits/stdc++.h>
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

int tt = 1;

int n, m;
string s;

bool valid(int r, int c) {
    return r >= 0 && r < 4 && c >= 0 && c < 4;
}

void sol() {
    cin >> s;
    vector<vector<int>> g(4, vector<int>(4, 0));
    bool vert = false;
    bool ho = false;
    for (int i = 0; i < sz(s); i++) {
        if (s[i] == '1') {
            cout << 1 << ' ' << 1 + 2 * ho << '\n';
            ho ^= 1;
        } else {
            cout << 3 - 2 * vert << ' ' << 4 << '\n';
            vert ^= 1;
        }
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

