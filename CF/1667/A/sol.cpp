#include<bits/stdc++.h>
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

int tt = 1;

int n, m, k;
string s;

void sol() {
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            b[j] = ((b[j + 1] / a[j]) + 1) * a[j];
            sum += (b[j + 1] / a[j]) + 1;
        }
        for (int j = i + 1; j < n; j++) {
            b[j] = ((b[j - 1] / a[j]) + 1) * a[j];
            sum += (b[j - 1] / a[j]) + 1;
        }
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

