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
#define fi first
#define se second
#define int long long
#define ll long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef vector<int> vi;
typedef pair<int, int> pii;

void sol();

int case_num = 0;

int32_t main() {
    send help

    int tt;
    cin >> tt;
    while(tt--) {
        ++case_num;
        sol();
    }
}

void sol() {
    int n, k;
    cin >> n >> k;
    vi a(n);
    vector<int> freq(n + 1);
    for (auto &x: a) {
        cin >> x;
        freq[x]++;
    }

    for (auto &x: a) {
        if (freq[x] % k != 0) {
            cout << 0 << '\n';
            return;
        }
    }
    if (n % k != 0) {
        cout << 0 << '\n';
        return;
    }

    int ans = 0;
    vi m(n + 1);
    for (int i = 0, j = 0; i < n; i++) {
        while(j < n && m[a[j]] <= freq[a[j]] / k) {
            m[a[j]]++;
            if (m[a[j]] > freq[a[j]] / k) {
                m[a[j]]--;
                break;
            }
            j++;
        }
        ans += j - i;
        m[a[i]]--;
    }
    cout << ans << '\n';
}

