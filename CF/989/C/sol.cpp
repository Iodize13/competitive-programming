#include<bits/stdc++.h>
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

int tt = 1;

int n, m;
string s;

void sol() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    c--;
    d--;
    cout << 50 << ' ' << 50 << '\n';
    vector<vector<char>> g(50, vector<char>(50, 'D'));
    for (int i = 0; i < 7; i+= 2) {
        for (int j = 0; j < 50; j+= 2, a--) {
            if (a > 0) g[i][j] = 'A';
        }
    }
    for (int i = 7; i < 14; i+= 2) {
        for (int j = 0; j < 50; j+= 2, b--) {
            if (b > 0) g[i][j] = 'B';
        }
    }
    for (int i = 14; i < 21; i+= 2) {
        for (int j = 0; j < 50; j+= 2, c--) {
            if (c > 0) g[i][j] = 'C';
        }
    }
    for (int i = 22; i < 50; i++) {
        for (int j = 0; j < 50; j++) {
            g[i][j] = 'C';
        }
    }
    for (int i = 23; i < 30; i+= 2) {
        for (int j = 0; j < 50; j+= 2, d--) {
            if (d > 0) g[i][j] = 'D';
        }
    }

    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 50; j++) {
            cout << g[i][j];
        }
        cout << '\n';
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

