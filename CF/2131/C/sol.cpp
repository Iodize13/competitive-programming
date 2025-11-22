#include<bits/stdc++.h>
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

int tt = 1;

int n, m, k;
string s;

void sol() {
    cin >> n >> k;
    multiset<int> a;
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.insert(x % k);
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
        b[i] %= k;
    }

    for (int i = 0; i < n; i++) {
        if (a.count(b[i])) {
            a.extract(b[i]);
            continue;
        } else {
            if (a.count(k - b[i])) {
                a.extract(k -b[i]);
            } else {
                cout << "NO\n";
                return;
            }
        }
    }
    
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

