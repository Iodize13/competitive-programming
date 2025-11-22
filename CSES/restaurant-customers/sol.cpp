#include<bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;

void sol() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> c;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        c.push_back(a[i]);
        c.push_back(b[i]);
    }
    sort(all(a));
    sort(all(b));
    sort(all(c));
//    int cnt = 0;
//    int cntO = 0;
    int j = 0;
    int k = 0;
    int ans = 0;
    for (int i = 0; i < 2 * n; i++) {
        while(j < n && a[j] < c[i]) j++;
        while(k < n && b[k] < c[i]) k++;
        // cerr << "j: " << j << ", k: " << k << '\n';
        ans = max(ans, j - k);
    }
    cout << ans << '\n';
}

int main() {
    sol();
}
