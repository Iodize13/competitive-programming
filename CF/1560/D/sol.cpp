#include<bits/stdc++.h>
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < (b); ++i)

using namespace std;
int n, m, k;
string s;

void sol() {
    cin >> s;

    auto f = [&](string t) {
        //cerr << "t: " << t << '\n';
        string ns = s;
        int ret = 0;
        int i = 0, j = -1;
        for (; i < sz(t);) {
            j++;
            // //cerr << "i :" << i << '\n';
            while (j < sz(ns) && ns[j] != t[i]) {
                ret++;
                if (j >= sz(ns) - 1) break;
                j++;
            }
            // //cerr << "j: " << j << ", ret: " << ret << '\n';
            if (t[i] == ns[j]) {
                i++;
            } else break;
            if (j >= sz(ns) - 1) break;
        }
        // i = min(i, sz(t) - 1);

        //cerr << "ret: " << ret << '\n';
        // ret += sz(ns) - 1 - i + sz(t) - 1 - j;
        //cerr << "j: " << j << '\n';
        int rs = sz(ns) - j - 1;
        ret += rs;
        //cerr << "rs: " << rs << '\n';
        int rt = sz(t) - i;
        ret += rt;
        //cerr << "rt: " << rt << '\n';
        //cerr << "2, ret: " << ret << '\n';
        return ret;
    };

    int ans = INT64_MAX;
    for (int i = 0; (1LL << i) <= (int)1e18; i++) {

        string t = to_string((1LL << i));
        if (sz(t) - sz(s) > min(sz(s) * 2, ans)) continue;
        ans = min(ans, f(t));
    }

    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt = 1, testcase(1);
    cin >> testcase;

    while(testcase--) {
        sol();
        tt++;
    }
    return 0;
}

