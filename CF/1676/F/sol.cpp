#include<bits/stdc++.h>
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

int tt = 1;

int n, m;
string s;

void sol() {
    int k;
    cin >> n >> k;
    vector<int> a(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    
    int st = -1, en = -1;
    int cnt = 0;
    int mx = 0;
    int prev = -1;
    int lst = 0;
    for (auto it = mp.begin(); it != mp.end(); it++)  {
        if (it->first != prev + 1) {
            cnt = 0;
            if (it->second >= k) lst = it->first;
            // cerr << it->first << ' ' << it->second << '\n';
        }
        if (it->second >= k) {
            cnt++;
            if (cnt > mx) {
                mx = cnt;
                st = lst;
                en = it->first;
            }
        } else {
            cnt = 0;
            auto iw = next(it, 1);
            lst = iw->first;
        }
        prev = it->first;
    }

    if (st == -1) {
        cout << st << '\n';
        return;
    }

    cout << st << ' '  << en << '\n';
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

