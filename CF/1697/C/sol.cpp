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

void sol() {
    cin >> n;
    string s, t;
    cin >> s >> t;
    vector<int> freqs(27);
    vector<int> freqt(27);
    for (auto &x: s) freqs[x - 'a']++;
    for (auto &x: t) freqt[x - 'a']++;

    for (int i = 0; i < 27; i++) if (freqs[i] != freqt[i]) {
        cout << "NO\n";
        return;
    }

    string new_s = "";
    string new_t = "";
    for (int i = 0, j = 0; i < n; i++) {
        if (s[i] == 'b') {
            if (!new_s.empty() && new_s.back() == 'a') continue;
            else {
                j = max(j, i);
                while (j < n && s[j] == 'b') j++;
                if (j > n) break;
                if (s[j] != 'c') for (int k = 0; k < j - i; k++) new_s += 'b';
                i = j - 1;
                continue;
            }
        } else {
            new_s += s[i];
        }
    }

    for (int i = 0, j = 0; i < n; i++) {
        if (t[i] == 'b') {
            if (!new_t.empty() && new_t.back() == 'c') continue;
            else {
                j = max(j, i);
                while( j < n && t[j] == 'b') j++;
                if (j > n) break;
                if (t[j] != 'a') for (int k = 0; k < j - i; k++) new_t += 'b';
                i = j - 1;
                continue;
            }
        } else {
            new_t += t[i];
        }
    }
    
    int st = 0;
    for (int i = 0; i < sz(new_t) ;i++) {
        if (new_t[i] != 'b') {
            st = i;
            break;
        }
    }

    int en = sz(new_t) - 1;
    for (int i = sz(new_t) - 1; i >= 0; i--) {
        if (new_t[i] != 'b') {
            en = i;
            break;
        }
    }

    // cerr << "new_s: " << new_s << '\n';
    // cerr << "new_t: " << new_t << '\n';
    for (int i = st, j = 0; i < en + 1; i++) {
        if (new_t[i] != new_s[j]) {
            cout << "NO\n";
            return;
        }
        j++;
    }

    cout << "YES\n";
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

