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
void dbg2(vector<int> &array, int32_t n) {
  //cerr << "array -> [";
  for(int32_t i = 0; i < n; i++) {
    //cerr << array[i];
    //cerr << (i == n-1 ? "]" : ", ");
  }
  //cerr << '\n';
}

// void dbg(...) {
//     //cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
// }

int n, m, k;

void sol() {
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    map<int, int> freqa;
    map<int, int> freqb;

    auto f = [](int cur) {
        int ret = 0;
        while (cur > 0) {
            cur /= 10;
            ret++;
        }

        return ret;
    };

    int ans = 0;
    for (auto &x: a) {
        cin >> x;
        freqa[x]++;
    }

    // dbg2(a, n);

    for (auto &x: b) {
        cin >> x;
        freqb[x]++;
    }

    for (int i = 0; i < n; i++) {
        if (freqa[a[i]]) {
            if (freqb[a[i]]) {
                freqb[a[i]]--;
                freqa[a[i]]--;
                //cerr << "match a: " << a[i] << '\n';
            } else {
                if (int x = f(a[i]); x > 1) {
                    ans++;
                    //cerr << "a[i]: " << a[i];
                    freqa[a[i]]--;
                    a[i] = x;
                    //cerr << ", " << x << '\n';
                    freqa[a[i]]++;
                }
            }
        }

        if (freqb[b[i]]) {
            if (freqa[b[i]]) {
                freqb[b[i]]--;
                freqa[b[i]]--;
                //cerr << "match b: " << b[i] << '\n';
            } else {
                if (int x = f(b[i]); x > 1) {
                    ans++;
                    //cerr << "b[i]: " << b[i];
                    freqb[b[i]]--;
                    b[i] = x;
                    //cerr << ", " << x << '\n';
                    freqb[b[i]]++;
                }
            }
        }
    }

    //cerr << "ans: " << ans << '\n';

    for (int i = 2; i <= 9; i++) {
        ans += abs(freqa[i] - freqb[i]);
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

