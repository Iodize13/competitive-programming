#include<bits/stdc++.h>

using namespace std;

using ll = long long;

map<int, int> v;

void runcase() {
    vector<vector<char>> g(3, vector<char>(3));
    for (int i = 0; i < 3; i++) 
        for (int j = 0; j < 3; j++) 
            cin >> g[i][j];

    int ta = 0;
    for (int i = 0, k = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++, k++) {
            if (g[i][j] == '*') ta += (1 << k);
        }
    }
    // cerr << ta << '\n';
    int tmp2 = ta;
    int o;
    while(tmp2) {
        cerr << (tmp2&1);
        tmp2>>=1;
        ++o;
    }
    cerr << '\n';

    cout << v[ta] << '\n';
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll testcase; cin >> testcase;
    v.clear();
    for (int i = 0; i <= (1<<9) - 1; i++) {
        int tmp = i;
        int k = 0;
        int cur = 0;
            while(tmp) {
                if (tmp&1) {
                    cur ^= (1<< (k));
                    if (k >= 3) cur ^= (1 << (k - 3));
                    if (k <= 5) cur ^= (1 << (k + 3));
                    if (k % 3 >= 1) cur ^= (1 << (k - 1));
                    if (k % 3 <= 1) cur ^= (1 << (k + 1));
                }
                tmp>>=1;
                ++k;
            }
        // cerr << cur << '\n';
        if (!v.count(cur)) v[cur] = __builtin_popcount(i);
        else v[cur] = min(v[cur], __builtin_popcount(i));
    }
    while(testcase--) {
        runcase();
    }
    return 0;
}
