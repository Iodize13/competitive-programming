#include "bits/stdc++.h"
#define int long long
#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()

using namespace std;

void sol() {
    int n;cin >> n;
    vector<int> cards(1e4+9,0);
    int mn = 1e4 + 9;
    for(int i=0;i<n;i++) {
        int tmp; cin >> tmp;
        cards[--tmp]++;
        mn = min(mn, tmp);
    }

    int ans = 0;
    bool ch = false;
    int i = mn;
    int cnt = 0;
    while(true) {
        if (i == (int)1e4 + 8) {
            i = 0;
            if (cnt == (int)1e4 + 8) {
                break;
            }
            cnt = 0;
            continue;
        }
        if (cards[i] == 0) {
            cnt++;
            if (!ch) ans++;
            ch = true;
            i++;
            continue;
        }
        ch = false;
        cards[i]--;
        i++;
    }
    cout << ans << '\n';
}

int32_t main() {
    sol();
}
