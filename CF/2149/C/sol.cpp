// #pragma GCC optimize("O3,unroll-loops")
#include "bits/stdc++.h"

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define dbg(...) 42
#endif
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
#define f first
#define s second
#define int long long
#define ll long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef vector<int> vi;
typedef pair<int, int> pii;
const int di[4] = {0, 0, -1, 1};
const int dj[4] = {-1, 1, 0, 0};



const bool TC = 1;
void solve() {
    int n, k;
    cin >> n >> k;
    vi a(n), freq(n + 2);
    for (auto &x: a) {
        cin >> x;
        freq[x]++;
    }

    int cur = 0;
    while(freq[cur]) cur++;
    // == ? 0
    if (cur == k) {
        cout << 0 << '\n';
        return;
    }
    int ans = 0, sum = 0;
    if (k > cur) {
        rep(i, cur, k) {
            if (freq[i] == 0) {
                if (freq[k] > 0) freq[k]--;
                else break;
            }
        }
        rep(i,0,k) {
            if (freq[i] == 0) {
                ans++;
            }
        }
    }

    
    ans += freq[k];
    cout << ans << '\n';
}

int32_t main() {
    send help

    int tt = 1;
    if (TC) cin >> tt;
    while (tt--) solve();
}

