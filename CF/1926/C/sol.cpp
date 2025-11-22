#include<bits/stdc++.h>
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

int tt = 1;

int n, m, k;
string s;

vector<int> pref((int)2e5 + 1);

void sol() {
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int testcase(1);
    cin >> testcase;
    for (int i = 1; i <= (int)2e5; i++) {
        int sum = 0;
        int temp = i;
        while (temp) {
            sum += temp % 10;
            temp /= 10;
        }
        pref[i] = pref[i - 1] + sum;
    }
    while(testcase--) {
        cin >> n;
        cout << pref[n] << '\n';
        tt++;
    }
    return 0;
}

