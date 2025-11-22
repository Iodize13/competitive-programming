#include<bits/stdc++.h>
#define int long long
#define all(x) (x).begin(), (x).end()

using namespace std;

vector<int> pref;

int calD(int idx, int sum, int last) {
    // cerr << (sum * idx) - pref[idx] << '\n';
    return ((sum * idx) - pref[idx + 1]) + ((pref[last + 1] - pref[idx]) - sum * (last - idx));
}

void sol() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) 
        cin >> a[i];

    sort(all(a));
    int sum = 0;
    pref.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] + a[i - 1];

    int diff = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        auto it = lower_bound(a.begin(), next(a.begin(), i), (int)round(sum / (long double)(i + 1))) - a.begin();
        cerr << "sum: " << sum << '\n';
        cerr << (int)round(sum / (long double)(i + 1)) << '\n';
        diff = calD(it, (int)round(sum / (long double)(i + 1)), i);
        cerr << "i: " << i << ' ' << diff << '\n';
        // while(r - l > 3) {
        //     int m1 = l + (r  -l) /3;
        //     int m2 = r - (r - l) /3;
        //     int f1 = f(m1);
        // }
    }
    cout << diff << '\n';
}

int32_t main() {
    int tt;
    cin >> tt;
    while(tt--) sol();
}
