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
#include <cmath>
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < (b); ++i)

using namespace std;
int n, m, k;

void sol() {
    cin >> n;
    int ans = 0;
    while (n > 0) {
        long double temp = n;
        int base = (int)(log(temp) / log(3.L));
        if (base == 0) {
            ans += n * 3LL;
            break;
        }
        int t = n / (int)pow(3LL, base);
        int cost = (int)pow(3LL, base + 1LL) + base * (int)(pow(3LL, base - 1LL));
        ans += t * cost;
        n %= (int)pow(3LL, base);
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

