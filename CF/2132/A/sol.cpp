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
int n, m;
string s;

void sol() {
    cin >> n;
    cin >> s;
    cin >> m;
    string t, u;
    cin >> t >> u;
    string f = "";
    for (int i = 0; i < m; i++) {
        if (u[i] == 'V') {
            f += t[i];
        } else {
            s += t[i];
        }
    }
    reverse(all(f));
    f += s;
    cout << f << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt = 1, testcase(1);
    cin >> testcase;

    while(testcase--) {
        sol();
        tt++;
    }
    return 0;
}

