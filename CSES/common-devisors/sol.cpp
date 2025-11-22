#include <bits/stdc++.h>
#define int long long

using namespace std;

void runcase(){
    int n;
    cin >> n;
    int ans = 0;
    vector<int> a((int)1e6 + 1, 0);
    for (int i = 0; i < n; i++) {
        int h;
        cin >> h;
        if (a[h]) ans = max(ans, h);
        a[h]++;
    }

    for (int i = 1; i <= (int)1e6; i++) {
        int cnt = 0;
        for (int j = i; j <= (int)1e6; j+= i) {
            if (a[j]) cnt++;
        }
        if (cnt >= 2) ans = max(ans, i);
    }

    cout << ans << '\n';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    runcase();
    return 0;
}
