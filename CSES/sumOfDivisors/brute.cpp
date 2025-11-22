#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MOD = (int)1e9 + 7;

void runcase(){
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1;i <=n ; i++) {
        ans = (ans + (((n / i) % MOD) * i%MOD) % MOD) % MOD;
    }

    cout << ans << '\n';
}


// 1 
// 1 2
// 1 3
// 1 2 4
// 1 5
// 1 2 3 6
// 1 7
// 1 2 4 8
// 1 3 9
// 1 2 5 10
// 1 11
// 1 2 3 4 6 12
// 1 13
// 1 2 7 14
// 1 3 5 15
// 1 2 4 8 16
//
// 10 + 2 * 5 + (3 + 4) * 4

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    runcase();
    return 0;
}
