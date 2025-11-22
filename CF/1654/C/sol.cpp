#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <array>
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < (b); ++i)

using namespace std;
int n, m, k;

void sol() {
    int sum = 0;
    cin >> n;     
    priority_queue<int> a,b;
    rep(i,0,n) {
        int x;
        cin >> x;
        a.push(x);
        sum += x;
    }

    b.push(sum);

    while (!(a.empty() || b.empty())) {
        int a0 = a.top();
        int b0 = b.top();
        if (a0 == b0) {
            a.pop();
            b.pop();
        } else if (a0 > b0) {
            cout << "NO\n";
            return;
        } else {
            int first = b0 / 2;
            int second = (b0 + 1) / 2;
            b.pop();
            b.push(first);
            b.push(second);
        }
    }

    cout << (a.empty() && b.empty() ? "YES" : "NO") << '\n';
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

