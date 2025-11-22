#include<bits/stdc++.h>
#define int long long int

using namespace std;

void runcase() {
    int n, px, py, qx, qy;
    cin >> n >> px >> py >> qx >> qy;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a.begin(), a.end());
    int l = a.back();
    for (int i = 0; i < n - 1; i++) l -= a[i];
    l = max(l, 0LL);
    int r = 0;
    for (int i = 0; i < n; i++) r += a[i];
    int d = (qx - px) * (qx - px) + (qy - py) * (qy - py);
    cout << (d >= l * l && d <= r * r ? "YES" : "NO") << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--) {
        runcase();
    }
	return 0;
}
