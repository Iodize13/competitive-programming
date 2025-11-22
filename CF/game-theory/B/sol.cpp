#include<bits/stdc++.h>
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

int tt = 1;

int n, m, k;
string s;

void sol() {
    cin >> n >> m;
    map<string, int> a;
    map<string, int> b;
    for (int i = 0; i < n; i++) {
        string H;
        cin >> H;
        a[H] = 0;
    }

    for (int i = 0; i < m; i++) {
        string H;
        cin >> H;
        if (a.count(H)) {
            a[H] = 1;
            b[H] = 1;
        } else {
            b[H] = 0;
        }
    }
    
    vector<pair<string, int> > po(a.begin(), a.end());
    vector<pair<string, int> > en(b.begin(), b.end());
    
    sort(all(po), [](const pair<string, int> &c, const pair<string, int> &d) {
        if (c.second == d.second) return c.first < d.first;
        return c.second < d.second;
    });
    sort(all(en), [](const pair<string, int> &c, const pair<string, int> &d) {
        if (c.second == d.second) return c.first < d.first;
        return c.second < d.second;
    });

    while (!po.empty() && !en.empty()) {
        if (po.back().second) {
            po.pop_back();
            en.pop_back();
        } else {
            po.pop_back();
        }
        if (en.empty()) {
            cout << "YES\n";
            return;
        }
        if (po.empty()) {
            cout << "NO\n";
            return;
        }
        if (en.back().second) {
            po.pop_back();
            en.pop_back();
        } else {
            en.pop_back();
        }
        if (po.empty()) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int testcase(1);
    while(testcase--) {
        sol();
        tt++;
    }
    return 0;
}

