#include<bits/stdc++.h>
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

int tt = 1;

int n, m;
string s;

void sol() {
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) 
        cin >> a[i];

    sort(all(a));
    if (n == 2) {
        cout << a[0] << ' ' << a[1] << '\n';
        return;
    }
    int mn = LLONG_MAX;
    for (int i = 1 ; i < n; i++) {
        mn = min(mn, abs(a[i - 1] - a[i]));
    }

    int sta = 0;
    for (int i = 1; i < n; i++) {
        if (abs(a[i - 1] - a[i]) == mn) {
            sta = i;
            break;
        }
    }

    for (int i = sta; i < n; i++) {
        cout << a[i] << ' ';
    }
    for (int i = 0; i < sta; i++) { 
        cout << a[i] << " \n"[i == sta -1];
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int testcase(1);
    cin >> testcase;
    while(testcase--) {
        sol();
        tt++;
    }
    return 0;
}

