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
    vector<int> a(n - 1);
    bool firstOk = true;
    int pref = n;
    for (int i = 0; i < n -1; i++) {
        cin >> a[i];
        pref += n - i - 1;
        if (a[i] > pref) firstOk = false;
    }

    if (!firstOk) {
        cout << "NO\n";
        return;
    }

    vector<int> b;
    int st = 0;
    vector<int> c(n +1);
    int mx = ((n + 1) * n) / 2;
    vector<int> ans;
    map<int,int> mp;
    bool bad = false;
    bool badin = false;
    for (int i = 1; i < n - 1; i++) {
        b.push_back(a[i] - a[i - 1]);
        if (a[i] - a[i - 1] <= n) {
            c[a[i] - a[i - 1]] = 1;
            // cerr << "c[a[i] - a[i - 1]]: " << a[i] - a[i - 1] << '\n';
            if (mp[a[i] - a[i - 1]]) {
                st = i;
                bad = true;
                badin = true;
            } else {
                ans.push_back(a[i] - a[i - 1]);
            }
            mp[a[i] - a[i - 1]] = 1;
        }
        else {
            if (bad) {
                // cerr << "case 2\n";
                cout << "NO\n";
                return;
            }
            bad = true;
            st = i - 1;
            if (a[i] - a[i - 1] > mx) {
                // cerr << "case 3\n";
                cout << "NO\n";
                return;
            }
        }
        // if (st.insert(b.back()).second == 0) {
        //     cout << "
        // }
        // ls += b.back();
    }
    if (badin) {
        cerr << a[0]<< '\n';
        if (mp[a[0]]) {
            cout << "NO\n";
            return;
        }
        ans.emplace(ans.begin(), a[0]);
        c[a[0]] = 1;
    }

    // cerr << "st: " << st << endl;
    bool ok = false;
    vector<int> con(all(ans));
    st = min(sz(ans), st);
    // for (auto &X: con) cerr << X << ' ';
    for (int i = 1; i < n + 1; i++) {
        if (c[i] == 0) {
            // cerr << "i: " << i << '\n';
            con.emplace(con.begin() + st, i);
            ok = true;
        }
    }
    // cerr << "st: " << st << '\n';
    for (auto &X: con) cerr << X << ' ';
    cerr << '\n';
    vector<int> perm(n + 1);
    int cnt = 0;
    for (int i = 0; i < sz(con); i++) {
        if (con[i] > n) {
            // cerr << "case 4\n";
            cout << "NO\n";
            return;
        }
        if (perm[con[i]]) {
            // cerr << "case 5\n";
            cout << "NO\n";
            return;
        }
        if (con[i] == 0) {
            // cerr << "case 6\n";
            cout << "NO\n";
            return;
        }
        perm[con[i]] = 1;
        cnt++;
    }
    if (!ok || cnt != n) {
        // cerr << "case 6\n";
        cout << "NO\n";
        return;
    }
    // for (int i = 0; i < n
    cout << "YES\n";
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

