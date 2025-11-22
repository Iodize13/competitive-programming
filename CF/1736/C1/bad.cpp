#include<bits/stdc++.h>
#define int long long

using namespace std;

int testcase = 0;

void sol() {
    int n;
    cin >> n;
    vector<int> A(n + 1, 0);
    for (int i = 0; i < n; i++)
        cin >> A[i];

    if (testcase == 31) {
        string ret = to_string(n) + ":";
        for (auto &x: A) {
            ret += to_string(x) + ",";
        }

        cout << ret << '\n';
    }

    int cnt = 1;
    int ans = 0;
    bool ok = false;
    for (int i = 0; i < n + 1; i++) {
        if (A[i] < cnt) {
            if (n - 1 == i) ok = true;
            cnt--;
            ans += ((cnt + 1) * (cnt)) / 2;
            cnt = min(A[i], cnt);
        }
        cnt++;
    }
    cnt--;
    // if (!ok) ans += ((cnt + 1) * (cnt)) / 2;
    cout << ans << '\n';
}

int32_t main() {
    int tt;
    cin >> tt;
    while(tt--) {
        testcase++;
        sol();
    }
}
