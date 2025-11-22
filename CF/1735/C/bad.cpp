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
    cin >> n;
    string s;
    cin >> s;
    vector<int> par(27);
    vector<int> vis(27);
    vector<int> child(27);
    if (s[0] == 'a') par[s[0] - 'a'] = 1;
    else par[s[0] - 'a'] = 0;
    string ans ="";
    int cnt = par[s[0] - 'a'] + 1;
    for (int i = 1; i < n; i++) {
        int cur = s[i] - 'a';
        if (vis[s[i] - 'a']) continue;
        int depth = 0;
        do {
            if (!vis[cur]) break;
            cur = child[cur];
            depth++;
        } while (cur != s[i] - 'a');

        cerr << "dpeth: " << depth << '\n';

        if (cnt == 26) {
            par[s[i] - 'a'] = 0;
        }
        else {
            par[s[i] - 'a'] = cnt++;
            child[cnt - 1] = s[i] - 'a';
        }
        vis[cnt] = 1;
    }

    for (int i = 0; i < n; i++) {
        cout << char('a' + par[s[i] - 'a']);
    }
    cout << '\n';
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

