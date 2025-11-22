#include<bits/stdc++.h>
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < (b); ++i)

using namespace std;
int n, m;
string s;

void sol() {
    cin >> s;    
    cin >> n;
    vector<string> a(n);
    for (auto &x: a)
        cin >> x;

    auto f = [&](string t) {
        int ret = INT64_MAX;
        for (int i = 0; i < sz(s); i++) {
            int saved = 0;
            int k = i;
            while(saved < sz(t) && k < sz(s)) {
                if (t[saved] == s[k]) {
                    saved++;
                    k++;
                } else {
                    k++;
                }
            }
            
            if (saved == sz(t)) {
                // cerr << "k - saved: " << k - saved - i << '\n';;
                ret = min(ret, k - saved - i);
            }
        }

        ret = (ret == INT64_MAX ? -1 : ret);
        return ret;
    };

    for (auto &x: a) cout << f(x) << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt = 1, testcase(1);

    while(testcase--) {
        sol();
        tt++;
    }
    return 0;
}

