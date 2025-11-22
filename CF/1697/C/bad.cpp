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
    string s, t;
    cin >> s >> t;
    vector<int> freqs(27);
    vector<int> freqt(27);
    for (auto &x: s) freqs[x]++;
    for (auto &x: t) freqt[x]++;

    for (int i = 0; i < 27; i++) if (freqs[i] != freqt[i]) {
        cout << "NO\n";
        return;
    }

    for (int i = n - 1, j = n - 1; i >= 1; i--) {
        if (s[i] == t[i]) continue;
        if (s[i] < t[i]) {
            // //cerr << "s: " << s << '\n';
            // //cerr << "t: " << t << '\n';
            // //cerr << "i: " << i << '\n';
            cout << "NO\n";
            return;
        }
        j = min(i - 1, j);
        while(j >= 0 && s[j] != t[i] && s[j] <= s[i]) {
            j--;
        }
        // what if it really hit the bound?
        if (j < 0 || s[i] - s[j] > 1) {
            // //cerr << "test\n";
            cout << "NO\n";
            return;
        }
        //cerr << "i: " << i << '\n';
        //cerr << "j: " << j << '\n';
        swap(s[j], s[i]);
        if (t[i] != s[i]) {
            // //cerr << "test\n";
            cout << "NO\n";
            return;
        }
    }

    // //cerr << "s: " << s << '\n';
    // //cerr << "t: " << t << '\n';

    cout << (s == t ? "YES" : "NO") << '\n';
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

