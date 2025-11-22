#include<bits/stdc++.h>
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;
int n, m;

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt = 1, testcase(1);
    string s;

    auto sol = [&]() {
        cin >> n;
        deque<int> l;
        deque<int> r;
        for (int i = 0; i < n; i++) {
            cin >> s;
            if (s == "push_back") {
                int k;
                cin >> k;
                r.push_back(k);
            } else if (s == "push_front") {
                int k;
                cin >> k;
                l.push_front(k);
            } else if (s == "push_middle") {
                int k;
                cin >> k;
                l.push_back(k);
            } else {
                int k;
                cin >> k;
                if (k >= sz(l)) {
                    cout << r[k - sz(l)] << '\n';
                } else {
                    cout << l[k] << '\n';
                }
            }
            while (sz(r) + ((sz(l) + sz(r))%2) > sz(l)) {
                int x = r.front();
                r.pop_front();
                l.push_back(x);
            }

            while(sz(r) + ((sz(l) + sz(r))%2) < sz(l)) {
                int x = l.back();
                l.pop_back();
                r.push_front(x);
            }
            // cerr << sz(l) << ' ' << sz(r) << '\n';
        }
    };

    while(testcase--) {
        sol();
        tt++;
    }
    return 0;
}

