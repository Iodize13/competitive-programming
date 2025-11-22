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
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < (b); ++i)

using namespace std;
int n, m, k;

const int N = 200'001;
int even[N + 1][27];
int odd[N + 1][27];
void sol() {
    memset(even, 0, sizeof even);
    memset(odd, 0, sizeof odd);
    cin >> n;
    string s;
    cin >> s;
    vector<int> odd(27);
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            even[i][s[i] - 'a']++;
        } else {
            odd[i][s[i] - 'a']++;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 27; j++) {
            
        }
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

