#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <deque>
#include <stack>
#include <cstdint>
#include <bitset>
#include <cstring>
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < (b); ++i)

using namespace std;
int n, m, k;

void sol() {
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    vector<vector<int> > a(27, vector<int>(n));
    vector<vector<int> > b(27, vector<int>(n));
    for (int i = 0; i < n; i++) {
        a[s[i] - 'a'][i]++;
        b[t[i] - 'a'][i]++;
    }

    // cerr << "test" << endl;
    
    vector<vector<int> > prefa(27, vector<int>(n + 1));
    vector<vector<int> > prefb(27, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 27; j++) {
            prefa[j][i] = prefa[j][i - 1] + a[j][i - 1];
            prefb[j][i] = prefb[j][i - 1] + b[j][i - 1];
        }
    }

    // cerr << "test" << endl;

    for (int i = 0; i < m; i++) {
        int l ,r;
        cin >> l >> r;
        int sum = 0;
        for (int j = 0; j < 27 ; j++) {
            // cerr << "dbg: " << prefa[j][r] << '\n';
            // cerr << "dbg: " << prefa[j][l - 1] << '\n';
            int temp = prefb[j][r] - prefb[j][l - 1];
            temp = abs(temp - prefa[j][r] + prefa[j][l - 1]);
            sum += temp;
        }

        cout << sum / 2 << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt = 1, testcase(1);
    string s;
    cin >> testcase;

    while(testcase--) {
        sol();
        tt++;
    }
    return 0;
}

