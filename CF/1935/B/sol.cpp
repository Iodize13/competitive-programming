#include<bits/stdc++.h>
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

int tt = 1;

int n, m;
string s;

void sol() {
    cin >> n;
    vector<int> a(n);
    vector<int> b(n + 1, 0);
    for (int i = 0; i < n ;i++) {
        cin >> a[i];
        if (a[i] <= n) b[a[i]]++;
    }

    int reM = 0;
    int mex = 0;
    while (b[mex]) mex++;
    while (b[reM] >= 2) reM++;
    if (reM != mex) {
        cout << "-1\n";
        return;
    }

    set<int> st;
    for (int i = 0; i < reM; i++) st.insert(i);

    set<int> temp = st;
    bool ok = false;
    bool win = false;
    int be = -1;
    vector<bool> c(reM, 0);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < reM) {
            if (!c[a[i]]) cnt++;
            c[a[i]] = 1;
        }
        if (cnt == reM) {
            if (ok) win = true;
            if (!ok) be = i;
            ok = true;
            cnt = 0;
            c.assign(reM, 0);
        }
    }

    if (!win) {
        cout << "-1\n";
        return;
    }

    cout << 2 << '\n';
    cout << 1 << ' ' << be + 1 << '\n';
    cout << be + 2 << ' '<< n << '\n';
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

