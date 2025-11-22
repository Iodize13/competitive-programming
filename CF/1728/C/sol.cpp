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
    priority_queue<int> a;
    priority_queue<int> b;
    rep(i,0,n) {
        int x;
        cin >> x;
        a.push(x);
    }

    rep(i,0,n) {
        int x;
        cin >> x;
        b.push(x);
    }

    auto f = [](int x) {
        return sz(to_string(x));
    };

    int ans = 0;
    while (!(a.empty() || b.empty())) {
        int a0 = a.top();
        int b0 = b.top();
        if (a0 == b0) {
            a.pop();
            b.pop();
            continue;
        }
        if (a0 > b0) {
            a.pop();
            a.push(f(a0));
            ans++;
        } else {
            b.pop();
            b.push(f(b0));
            ans++;
        }
    }

    cout << ans << '\n';
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

