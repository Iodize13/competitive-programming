#include<bits/stdc++.h>
#define int long long
#define ll long long
#define sz(x) (int)(x).size()

using namespace std;

void sol() {
    int n;
    cin >> n;
    int tmp = n;
    string ans = "";
    while(tmp) {
        ans += char(tmp % 8 + '0');
        tmp /= 8;
    }
    reverse(ans.begin(), ans.end());
    bool ok = false;
    int cnt2 = 0;
    while (!ok) {
        int cnt = 0;
        int sum = 0;
        for (int i = ans.size() -1 ; i >= 0;i--) {
            if (i == 0) ok = true;
            if (ans[i] == '0') {
                sum += (cnt + 1 + cnt2) * (int)pow(10, cnt);
                cnt++;
            }
            else break;
        }
        cnt2--;
        ans = to_string(stoll(ans) - sum);
    }
    cout << ans << '\n';
}

int32_t main(int32_t argc, char* argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    clock_t HZA = clock();
    sol();
    cerr << fixed << (double)(clock() - HZA) / CLOCKS_PER_SEC << setprecision(5) << '\n';
}
