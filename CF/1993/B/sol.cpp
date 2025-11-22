#include<bits/stdc++.h>
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

int tt = 1;

int n, m, k;
string s;

void sol() {
    cin >> n;
    multiset<int> a;
    multiset<int> b;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x % 2 == 0) a.insert(x);
        else b.insert(x);
    }

    if (sz(a) == 0 || sz(b) == 0) {
        cout << "0\n";
        return;
    }

    int ans = 0;
    while (!a.empty()) {
        int last = *prev(b.end());
        auto it = a.lower_bound(last);
        if (it == a.begin()) {
            b.insert(last + *prev(a.end()));
            b.extract(last);
        } else {
            --it;
            b.insert(last + *it);
            a.extract(it);
        }
        ans++;
    }

    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int testcase(1);
    cin >> testcase;
    while(testcase--) {
        sol();
        tt++;
    }
    return 0;
}

