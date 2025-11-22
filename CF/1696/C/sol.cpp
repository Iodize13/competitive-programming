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
    cin >> n >> m;
    vector<int> a(n);
    for (auto &x: a)
        cin >> x;

    int k;
    cin >> k;
    vector<int> b(k);
    for (auto &x: b)
        cin >> x;
    
    vector<pair<int, int> > ex;
    for (auto &x: a) {
        int mul = 1LL;
        while (x % m == 0) {
            mul *= m;
            x /= m;
        }
        
        if (!ex.empty() && ex.back().first == x) {
            ex.back().second += mul;
        } else {
            ex.push_back({x, mul});
        }
    }

    bool ok = true;
    for (int i = 0, j = 0; i < k; i++) {
        if (j >= sz(ex)) {
            cout << "NO\n";
            return;
        }
        int mul = 1LL;
        while (ex[j].first * mul < b[i]) {
            if (ex[j].second < mul) {
                ok = false;
            }
            mul *= m;
        }
        if (ex[j].first * mul > b[i]) {
            ok = false;
            break;
        }

        ex[j].second -= mul;
        if (ex[j].second == 0) j++;
    }

    if (ex.back().second != 0) ok = false;

    cout << (ok ? "YES" : "NO") << '\n';
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

